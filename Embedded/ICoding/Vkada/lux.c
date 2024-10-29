/* Implement non-blocking version of get_most_recent_lux and get_lux_at */

/* Since read_next_sample blocks, cannot call this, another thread needs to call this fn*/
/* Needs to put in a Q/Cache */

/* Discussion: simple: if atomic variable, can use to lock the value */
/* Array: size needs to be finite, number of expected processes, spinlock */
/* Mutex for locking the Q, but mutex could lock */
/* Non-blocking: function should return in determinitic and short period of time? */
/* Not blocked for an extended period of time */
/* However if it is an interrupt context, simple mutex will not work */
/* non-blocking: thread cannot go to sleep? */

enum 
{
    ERROR = 0,
    NO_CHANGE = 1,
    VALUD = 2, 
};

typedef struct SensorReading {
    int status;
    float lux;
    uint64_t timestamp;
} SensorReading;

//Blocks up to 1 second; returns once value changes from previous; or NO_CHANGE
struct SensorReading read_next_sample(void);

/* Size of array depends on how fast read_next_sample is running */
SensorReading FIFO[10];
int HEAD=0,TAIL=-1; /* HEAD at element to be filled, TAIL at end */

/* Assume a 5ms thread to store the lux */
void task_5ms(void)
{
    /*Other aspects*/
    FIFO[HEAD]=read_next_sample();
    HEAD=(++HEAD)%10;
}

//Implement these non-blocking and thread-safe
float get_most_recent_lux() 
{ 
    /*TO DO*/
    /* Most recent value is where the HEAD-1 is */
    return FIFO[(HEAD-1)%10];
}

float get_lux_at(uint64_t timestamp) 
{
    /*TO DO*/
    /* Search the Q for the timestamp from 0 to 10? */
    /* If timestamp is lesser than TAIL, return value at tail */
    /* If timestamp is greater than HEAD, return value at HEAD */
    /* */
}
