/* Implement spin_lock using ARM instructions */

/* Spinlock */
/* Keep spinning until someone unlocks */

#define LOCKED  1
#define UNLOCKED    0

typedef struct 
{
    bool lock;
    bool ready_to_free;
} SL_t;

void SL_init(SL_t* sl)
{
    spinlocksAry[++counter] = sl;
}

void spin_lock()    // Called by ISR and held by ISR
{
    //
    while(*sl==LOCKED)
    {
        __WFE();
    }
    sl->lock = LOCKED;
}

void spin_free(SL_t* sl)
{
    sl->ready_to_free = true;
    __svc();
    //
}

void SVC_ISR()
{
    for(int i=0; i< SPINLOCK_MAX; i++)
    {
        if(spinlockAry[i]->ready_to_free)
        {
            spinlockAry[i].ready_to_free = false;
            spinlockAry[i]->lock = FREE;
        }
    }
}
