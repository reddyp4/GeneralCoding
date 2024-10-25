/* Read a 128bit time-stamp on 64-bit machine */
/* two registers? function with value? 
atomic variable that is incrementing on a timer 
std::atomic -> 
interrupted when rollover of lower value */

/* This is like a single producer, multiple consumer problem */
/* When consuimg, producer cannot modify */
/* When producing, value is locked and inaccessible */
/* However just using a mutex can create a dead-lock, if producer is higher priority */
/* Use CV to signal other threads, to proceed */
/* Other idea, depending on how accurate, can use a circular buffer */

/* C: use atomic library */
#include<stdatomic.h>
#include<stdint.h>
#include<stdio.h>
#include<pthread.h>

struct timeStamp 
{
    uint64_t high=0,low=0;
    pthread_mutex_t lock;
    pthread_cond_t cv;
};

/* Function called in timer */
void update()
{
    /* Lock mutex with timer is updating, read not allowed */
    pthread_mutex_lock(&timeStamp.lock);
    atomic_fetch_add(low,1);
    /* check if high is ready to be changed */
    if(timeStamp.low==0)    pthread_cond_wait(&timeStamp.lock,&timeStamp.cv);
    atomic_fetch_add(timeStamp.high);
    pthread_cond_signal(&timeStamp.lock,&timeStamp.cv);
    pthread_mutex_unlock(&timeStamp.lock);
    /* Unlock mutex once write is done */
}

/* Function can be called from anywhere */
/* Simple case: just read */
/* One issue: if interrupted and value changes in between */
void getTime(uint64_t* val)
{
    *val=timeStamp.low;
    /* Lock mutex with timer is updating, read not allowed */
    pthread_mutex_lock(&timeStamp.lock);
    /* check if overflow condition */
    if(timeStamp.low==0)    pthread_cond_wait(&timeStamp.lock,&timeStamp.cv);
    *(val+1)=timeStamp.high;
    pthread_cond_signal(&timeStamp.lock,&timeStamp.cv);
    pthread_mutex_unlock(&timeStamp.lock);
}
