/*
1116. Print Zero Even Odd
Medium
Topics
Companies
You have a function printNumber that can be called with an integer parameter and prints it to the console.

For example, calling printNumber(7) prints 7 to the console.
You are given an instance of the class ZeroEvenOdd that has three functions: zero, even, and odd. The same instance of ZeroEvenOdd will be passed to three different threads:

Thread A: calls zero() that should only output 0's.
Thread B: calls even() that should only output even numbers.
Thread C: calls odd() that should only output odd numbers.
Modify the given class to output the series "010203040506..." where the length of the series must be 2n.

Implement the ZeroEvenOdd class:

ZeroEvenOdd(int n) Initializes the object with the number n that represents the numbers that should be printed.
void zero(printNumber) Calls printNumber to output one zero.
void even(printNumber) Calls printNumber to output one even number.
void odd(printNumber) Calls printNumber to output one odd number.
 

Example 1:

Input: n = 2
Output: "0102"
Explanation: There are three threads being fired asynchronously.
One of them calls zero(), the other calls even(), and the last one calls odd().
"0102" is the correct output.
Example 2:

Input: n = 5
Output: "0102030405"
 

Constraints:

1 <= n <= 1000
*/

#include<pthread.h>

class ZeroEvenOdd {
private:
    int n;

public:
    int state;  //states:1-2-3-4, as per 0 1 0 2 
    int count;
    pthread_mutex_t M;
    pthread_cond_t CV;

    ZeroEvenOdd(int n) {
        this->n = n;
        pthread_mutex_init(&M,NULL);
        pthread_cond_init(&CV,NULL);
        count=0;
        state=1;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        //get mutex
        pthread_mutex_lock(&M);
        cout<<"Zero1:state:"<<state<<",count:"<<count<<""<<endl;
        if(count>this->n)   return;
        while(state==2 || state==4) pthread_cond_wait(&CV,&M);
        printNumber(0);
        state++;
        if(count==0)    count++;
        cout<<"Zero2:state:"<<state<<",count:"<<count<<""<<endl;
        pthread_mutex_unlock(&M);
        pthread_cond_broadcast(&CV);
    }

    void even(function<void(int)> printNumber) {
        if(count>this->n)   return;
        //get mutex
        pthread_mutex_lock(&M);
        cout<<"Even1:state:"<<state<<",count:"<<count<<""<<endl;
        //wait for CV, if number is odd
        while(state!=4)  pthread_cond_wait(&CV,&M);
        count++;
        state=1;
        printNumber(count);
        cout<<"Even2:state:"<<state<<",count:"<<count<<""<<endl;
        pthread_mutex_unlock(&M);
        pthread_cond_broadcast(&CV);
    }

    void odd(function<void(int)> printNumber) {
        if(count>this->n)   return;
        //get mutex
        pthread_mutex_lock(&M);
        cout<<"Odd1:state:"<<state<<",count:"<<count<<""<<endl;
        //wait for CV, if number is even
        while(state!=2)  pthread_cond_wait(&CV,&M);
        count++;
        state=3;
        printNumber(count);
        cout<<"Odd2:state:"<<state<<",count:"<<count<<""<<endl;
        pthread_mutex_unlock(&M);
        pthread_cond_broadcast(&CV);
    }
};
