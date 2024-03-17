/* Circular buffer variations */

/* 
File: 0001_simple_circ_buffer.c
Simple circular buffer given the size, with variation for overwritting
Single producer/single consumer

*/

/* 
One issue is how to know if it is empty or full
Option1: Use an empty slot between head and tail
Option2: Use a boolean flag 
*/

/*
Problem of slow consumer: 
*/

/*
Interrupt context?
*/

/*
Linux way? 
*/

/*
Sharing between interrupt context, spinlocks can be used - code?
otherwise, can use signal variable?
for single producer/consumer - CV/mutex lock is sufficient
for multiple consumers - use a spinlock
consumers - thread-based, buffer will driven by ISR

Usually
Mutex stack - LDRX
puts task in wait queue, and releases the context

For ISR, cannot come to interrupt context
TTBR

What is preferred in an ISR?
*/