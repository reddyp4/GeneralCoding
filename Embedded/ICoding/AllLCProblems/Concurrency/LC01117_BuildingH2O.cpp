/*
1117. Building H2O
Attempted
Medium
Topics
Companies
There are two kinds of threads: oxygen and hydrogen. Your goal is to group these threads to form water molecules.

There is a barrier where each thread has to wait until a complete molecule can be formed. Hydrogen and oxygen threads will be given releaseHydrogen and releaseOxygen methods respectively, which will allow them to pass the barrier. These threads should pass the barrier in groups of three, and they must immediately bond with each other to form a water molecule. You must guarantee that all the threads from one molecule bond before any other threads from the next molecule do.

In other words:

If an oxygen thread arrives at the barrier when no hydrogen threads are present, it must wait for two hydrogen threads.
If a hydrogen thread arrives at the barrier when no other threads are present, it must wait for an oxygen thread and another hydrogen thread.
We do not have to worry about matching the threads up explicitly; the threads do not necessarily know which other threads they are paired up with. The key is that threads pass the barriers in complete sets; thus, if we examine the sequence of threads that bind and divide them into groups of three, each group should contain one oxygen and two hydrogen threads.

Write synchronization code for oxygen and hydrogen molecules that enforces these constraints.

 

Example 1:

Input: water = "HOH"
Output: "HHO"
Explanation: "HOH" and "OHH" are also valid answers.
Example 2:

Input: water = "OOHHHH"
Output: "HHOHHO"
Explanation: "HOHHHO", "OHHHHO", "HHOHOH", "HOHHOH", "OHHHOH", "HHOOHH", "HOHOHH" and "OHHOHH" are also valid answers.
 

Constraints:

3 * n == water.length
1 <= n <= 20
water[i] is either 'H' or 'O'.
There will be exactly 2 * n 'H' in water.
There will be exactly n 'O' in water.
*/

/*
Water = 2*H+O precisely

getHLock
if(H==0 || H==1)    release H (either go to 1H or to 2H or to 1H+1O or to 2H+1O), release CV
else blockH

if(O==0)    release O   (either go to 1O or to 1H+1O or to 2H+2O)
else blockO

*/


#include<pthread.h>

class H2O {
public:
    int countH, countO,countW;
    pthread_mutex_t M_H,M_O;
    pthread_cond_t CV_H,CV_O;
    bool print=false;

    H2O() {
        countH=0;countO=0;countW=0;
        pthread_mutex_init(&M_H,NULL);
        pthread_cond_init(&CV_H,NULL);
        pthread_mutex_init(&M_O,NULL);
        pthread_cond_init(&CV_O,NULL);
    }

    void hydrogen(function<void()> releaseHydrogen) {
        if(print)   cout<<"Entering Hydrogen:"<<endl;
        pthread_mutex_lock(&M_H);

        if(print)   cout<<"Hydrogen Got Mutex:"<<endl;
        //Ideally
        while(countH>=2)  
        {
            //too much hydrogen, so block, wait and sit here, until countH goes down
            //but for countH to go down, only possibly by another Hydrogen thread or Oxygen thread
            //but new hydrogen shouldnt get the lock
            pthread_cond_wait(&CV_H,&M_H);
        }
        if(print)   cout<<"Got CV"<<endl;
        //if here countH<2, release H
        //else if(countH<=1) - 
            //releaseH;

        //we are here, have mutex
        countH++;
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        if(print)   cout<<"Released Hydrogen"<<"H1:countH:"<<countH<<",countO:"<<countO<<endl;

        //Check if water can formed
        if(countH==2 && countO==1)
        {
            //Water
            countH=0;countO=0;
            if(print)   cout<<"Formed Water"<<endl;
            pthread_cond_broadcast(&CV_O);
            pthread_mutex_unlock(&M_O);

            pthread_cond_broadcast(&CV_H);
            pthread_mutex_unlock(&M_H);
        }
        if(countH==1)
        {
            pthread_cond_broadcast(&CV_H);
            pthread_mutex_unlock(&M_H);
        }

        if(print)   cout<<"Ending Hydrogen: H2:countH:"<<countH<<",countO:"<<countO<<endl;
    }

    void oxygen(function<void()> releaseOxygen) {
        if(print)   cout<<"Entering Oxygen:"<<endl;
        pthread_mutex_lock(&M_O);

        if(print)   cout<<"Oxygen Got Mutex:"<<endl;
        //Ideally
        while(countO>1)
        {
            //sit here until this count goes down, when water is formed
            pthread_cond_wait(&CV_O,&M_O);
        }
        if(print)   cout<<"Got CV"<<endl;
        //if you are here, countO=0 or countO=1

        //we are here, have mutex
        countO++;
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        if(print)   cout<<"Released Oxygen"<<"O1:countH:"<<countH<<",countO:"<<countO<<endl;

        //Check if water can formed
        if(countH==2 && countO==1)
        {
            //Water
            countH=0;countO=0;
            if(print)   cout<<"Formed Water"<<endl;
            pthread_cond_broadcast(&CV_H);
            pthread_mutex_unlock(&M_H);

            pthread_cond_broadcast(&CV_O);
            pthread_mutex_unlock(&M_O);
        }
        if(print)   cout<<"Ending Oxygen: O2:countH:"<<countH<<",countO:"<<countO<<endl;
    }
};

/*
Test cases to watchout for:
"HHHHHHHHHHOHHOHHHHOOHHHOOOOHHOOHOHHHHHOOHOHHHOOOOOOHHHHHHHHH"
"OHOOHOHHHHOHHOHHHH"
"OOHHHH"
*/