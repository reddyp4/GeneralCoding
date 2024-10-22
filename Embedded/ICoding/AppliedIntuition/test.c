/*
Implement a SW timer API that allows for the tracking of multiple
different expiration times that is backed by a single hw timer.
Assumptions: The hw timer tick register is 32-bits with resolution
of 1 ms per tick.
You can ignore hw timer overflow
You can add any other needed data structures or invent hypothetical
functions to aid in your solition. 
Solution does not need to compile, but try to keep it read-able within
what the c language allows. */

typedef struct 
{
    /* data */
    callback_fn *cb;
    uint32_t duration_ms;
    uint32_t hw_timer_expiry: /* time at which you ar adding */
    sw_timer_t *next;
} sw_timer_t;

sw_timer_t HEAD;

//Provided functions.
uint32_t get_current_time_ms(void);
/* sets the expiry for IRQHandler to call hw_timer_isr */
void set_hw_timer_expiration_ms(uint32_t time_ms);
/* Enable or disable interrupts */
void interrupts_enabled(bool enable);

/* Callback after hw timer expiry */
void hw_timer_isr(void) {
    //TO DO
    /* we are here after hw timer expiry */
    if(HEAD.next!=NULL)
        HEAD.next.cb;
    if((HEAD.next)->next!=NULL)
    {
        HEAD.next=(HEAD.next)->next;
        set_hw_timer_expiration_ms((HEAD.next)->hw_timer_expiry-get_current_time_ms());
    }
}

/* Not linked to ISR, initialization function only */
void add_sw_timer(sw_timer_t *tmr)
{
    //TO DO
    /* Assign callback */
    sw_timer_t *node, *prev;
    node=HEAD.next;
    prev=HEAD;
    /* Two cases for changes, first time */
    /* if hw_timer_expiry < current ongoing hw_timer_expiry */
    if(prev!=HEAD)
    {
        set_hw_timer_expiration_ms(tmr->hw_timer_expiry);
    }
}

void callback_1(void)   { printf("callback 1 @ %d ms\n", 
            get_current_time_ms());}
void callback_2(void)   { printf("callback 2 @ %d ms\n", 
            get_current_time_ms());}

static sw_timer_t t1 = {.cb = callback_1, .duration_ms = 500};

static sw_timer_t t2 = {.cb = callback_2, .duration_ms = 2000};

int main(void) {
    printf("Start time: %u ms\n", get_current_time_ms());
    HEAD.duration_ms=0;
    HEAD.hw_timer_expiry=0;

    //t0
    add_sw_timer(&t1);
    add_sw_timer(&t2);

    //t=500ms
    //callback_1()

    //t=2000ms
    //callback_2()

    /* Note, the reverse order should have exact same behaviour as above: */
    /* add_sw_timer(&t2); */
    /* add_sw_timer(&t1); */

    while(true) {
    };
}