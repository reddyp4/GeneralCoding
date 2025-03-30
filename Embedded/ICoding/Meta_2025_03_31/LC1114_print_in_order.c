/*
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
Concurrency:
Mutex: lock 
Semaphore: 

include pthread.h

state of 1,2,3

first()
>get the lock
>wait for state of 1
  >if state!=1, put conditional variable to wait
>print
>unlock
>cond-var broadcast -- very important

second checks for state of 2
third checks for state of 3

first release lock to second, second release lock to third, and third release to one
https://www.cs.fsu.edu/~baker/realtime/restricted/notes/pthreads.html

*/

#include<pthread.h>

typedef struct {
    // User defined data may be declared here.
    pthread_mutex_t LOCK;
    pthread_cond_t COND;
    int state;
} Foo;

// Function Declaration, do not remove
void printFirst();
void printSecond();
void printThird();

Foo* fooCreate() {
    Foo* obj = (Foo*) malloc(sizeof(Foo));
    
    // Initialize user defined data here.
    pthread_mutex_init(&(obj->LOCK), NULL);
    pthread_cond_init(&(obj->COND),NULL);
    obj->state=1;
    return obj;
}

void first(Foo* obj) {
    /* Get the lock */
    pthread_mutex_lock(&(obj->LOCK));
    /* Wait until state reaches 1 */
    while(obj->state!=1)
    {
        pthread_cond_wait(&(obj->COND), &(obj->LOCK));
    }
    pthread_mutex_unlock(&(obj->LOCK));
    // printFirst() outputs "first". Do not change or remove this line.
    printFirst();
    obj->state=2;
    /* broadcast */
    pthread_cond_broadcast(&(obj->COND));
}

void second(Foo* obj) {
    /* Get the lock */
    pthread_mutex_lock(&(obj->LOCK));
    /* Wait until state reaches 2 */
    while(obj->state!=2)
    {
        pthread_cond_wait(&(obj->COND), &(obj->LOCK));
    }
    pthread_mutex_unlock(&(obj->LOCK));
    // printSecond() outputs "second". Do not change or remove this line.
    printSecond();
    obj->state=3;
    /* broadcast */
    pthread_cond_broadcast(&(obj->COND));
}

void third(Foo* obj) {
    /* Get the lock */
    pthread_mutex_lock(&(obj->LOCK));
    /* Wait until state reaches 3 */
    while(obj->state!=3)
    {
        pthread_cond_wait(&(obj->COND), &(obj->LOCK));
    }
    pthread_mutex_unlock(&(obj->LOCK));
    printThird();
    obj->state=1;
    /* broadcast */
    pthread_cond_broadcast(&(obj->COND));
}

void fooFree(Foo* obj) {
    // User defined data may be cleaned up here.
    
}