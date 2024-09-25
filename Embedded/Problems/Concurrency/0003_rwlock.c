/* Read Write Lock

Multiple readers, single writer
Rules: 
1) Once reader is in, any number of readers are allowed but not the writer
2) Once writer is in, no reader is allowed

*/

/* Libraries */
#include<pthread.h>
#include<stdio.h>
#include<uinstd.h>
#include<string.h>
#include<stdlib.h>

/* Global Variables */
int readCnt;    /* Number of readers, initially 0 */
pthread_mute_t count_lock, write_lock;

/* Lock for Writing */
void lock_for_writing(void)
{
    pthread_mutex_lock(&write_lock);
}

/* Unlock for writing */
void unlock_for_writing(void)
{
    pthread_mutex_unlock(&write_lock);
}

/* Lock for reading */
void lock_for_reading(void)
{
    pthread_mutex_lock(&count_lock);    /* Get the lock */
    readCnt++;
    if(readCnt == 1)   /* If first reader, wait until getting the writelock */
    {
        pthread_mutex_lock(&write_lock);    /* Only first reader gets the lock */
    }
    pthread_mutex_unlock(&count_lock);  /* Release lock upon exiting */
}

/* Unlock for reading */
void unlock_for_reading(void)
{
    pthread_mutex_lock(&count_lock);    /* Get the count lock for changing */
    readCnt--;
    if(readCnt==0)      /* Last Thread to leave, so release the write lock*/
    {
        pthread_mutex_unlock(&write_lock);
    }
    pthread_mutex_unlock(&count_lock);  /* Release the count lock */
}