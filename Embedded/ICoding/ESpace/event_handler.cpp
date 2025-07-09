/* Simulate an event handler system. Call the appropriate handler based on the event type. */
enum {
    EVENT_0,
    EVENT_1,
    EVENT_ALL
};

bool event_a_val;
uint32_t event; /* 1111 - DCBA */

void event_a()
{
    /* determines that event happened */
    event_a_val=EVENT_0;
}

void event_handler()
{
    switch(event)
    {
        case(event_a):
            /* action */
        default:
    }
}