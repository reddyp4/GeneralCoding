// Step1: Map, put [key,value], get(key) return a value
// keys are uint32_t, values are also uint32_t
// SIZE=100

// Problem1: multiple keys for same index

// Hashing function is available, given a key, I know the index where the key-value exists
// if key, index=hash(key), value=map_values(index)
// hash returns -1, if key is not present in map

#include<pthread.h>

uint32_t SIZE = 100;
uint32_t MAP_KEYS[100];
uint32_t MAP_VALUES[100];
uint32_t current_index;    //pointing to the last known index filled

// Multiple readers, multiple writers
// Map is shared resource

//lock-striping - divide map into 10 sections
//Java - 16 mutex based on regions for concurrent map

pthread_mutex_t mutex[10];
pthread_cond_t cv;
uint32_t ready;

bool put(uint32_t key, uint32_t value)
{
    //put will write value if key not present
    mutex_index = func1(key);
    pthread_mutex_lock(&mutex[mutex_index]);
    while(ready==1)
        pthread_cond_wait(&mutex,&cv);
    uint32_t current_value = MAP_VALUES[hash(key)];
    MAP_VALUES[hash(key)]=value;
    ready=0;
    if(current_value==-1)
    {
        pthread_mutex_unlock(&mutex);
        return True;
    }
    pthread_mutex_unlock(&mutex);
    return False;
}

// r1, r2, r1 gets the lock, r2 cannot get the lock, p1 

// read_write lock for multiple readers
// Example: Wikipedia, counter for pending writees

uint32_t get(uint32_t key)
{
    //if key is present, return its value, else return -1
    pthread_mutex_lock(&mutex);
    while(ready==0)        // if ready=0, wait until it is set by producer
        pthread_cond_wait(&mutex,&cv);
    ready=1;
    uint32_t value= MAP_VALUES[hash(key)];
    pthread_mutex_unlock(&mutex);
}

int main()
{
    pthread_init(&mutex);
    //initiazation for cv
    ready=0;        //intialized variable that buffer is available
}

// Talk while writing: Idea is to build solution part by part to final solution
// Doughlee, neil grafter -> Java Concurrency 