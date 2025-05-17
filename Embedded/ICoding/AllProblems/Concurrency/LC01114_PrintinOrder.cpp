/*
1114. Print in Order
Solved
Easy
Topics
Companies
Suppose we have a class:

public class Foo {
  public void first() { print("first"); }
  public void second() { print("second"); }
  public void third() { print("third"); }
}
The same instance of Foo will be passed to three different threads. Thread A will call first(), thread B will call second(), and thread C will call third(). Design a mechanism and modify the program to ensure that second() is executed after first(), and third() is executed after second().

Note:

We do not know how the threads will be scheduled in the operating system, even though the numbers in the input seem to imply the ordering. The input format you see is mainly to ensure our tests' comprehensiveness.

 

Example 1:

Input: nums = [1,2,3]
Output: "firstsecondthird"
Explanation: There are three threads being fired asynchronously. The input [1,2,3] means thread A calls first(), thread B calls second(), and thread C calls third(). "firstsecondthird" is the correct output.
Example 2:

Input: nums = [1,3,2]
Output: "firstsecondthird"
Explanation: The input [1,3,2] means thread A calls first(), thread B calls third(), and thread C calls second(). "firstsecondthird" is the correct output.
 

Constraints:

nums is a permutation of [1, 2, 3].
*/
/*
Method1: Use pthread.h functions, use single mutex and cv (tied to mutex)
    say first()
        get lock
        wait for turn, say variable=1, so while!=1, wait for mutex, with cv
        print
        release lock
        broadcast (or saying its done)
*/

#include<pthread.h>

class Foo {
public:
    int state=1;
    pthread_mutex_t m;
    pthread_cond_t cv;

    Foo() {
        pthread_mutex_init(&m,NULL);
        pthread_cond_init(&cv,NULL);
    }

    void first(function<void()> printFirst) {
        //get the lock
        pthread_mutex_lock(&m);
        while(state!=1)
            pthread_cond_wait(&cv,&m);  //wait for cv
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        //release lock
        pthread_mutex_unlock(&m);
        //broadcast cv
        pthread_cond_broadcast(&cv);
        state=2;
    }

    void second(function<void()> printSecond) {
        //get the lock
        pthread_mutex_lock(&m);
        while(state!=2)
            pthread_cond_wait(&cv,&m);  //wait for cv
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        //release lock
        pthread_mutex_unlock(&m);
        //broadcast cv
        pthread_cond_broadcast(&cv);
        state=3;
    }

    void third(function<void()> printThird) {
        //get the lock
        pthread_mutex_lock(&m);
        while(state!=3)
            pthread_cond_wait(&cv,&m);  //wait for cv
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        //release lock
        pthread_mutex_unlock(&m);
        //broadcast cv
        pthread_cond_broadcast(&cv);
        state=1;
    }
};

/*
Runtime 7ms Beats 49.41%
Analyze Complexity
Memory 9.51MB Beats 48.79%
*/