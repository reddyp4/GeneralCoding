Lock implementation - Consider the following implementation of lock for mutual exclusion in a  critical section. 



The critical section is within each Thread ‘i’ and is protected by calls to functions lock() and unlock().



Lock and Unlock Usage:

 Thread(integer i) {



     while (true) {



         lock(i);



         // The critical section goes here...



         unlock(i);



         // non-critical section...



     }



Where integer parameter i is the identity of the Thread. 



Lock and unlock implementation:

 // declaration and initial values of global variables



 choosing: array [1..NUM_THREADS] of bool = {false};



 Number: array [1..NUM_THREADS] of integer = {0};





lock(integer i) {



     choosing[i] = true;



     Number[i] = 1 + max(Number[1], ..., Number[NUM_THREADS]); 



     choosing[i] = false;



     for (integer j = 1; j <= NUM_THREADS; j++) {



         // Wait until thread j receives its number:



         while (choosing[j]) { /* nothing */ }



         // Wait until all threads with smaller numbers or with the same



         // number, but with higher priority, finish their work:



         while ((Number[j] != 0) && ((Number[j] < Number[i]) || ((Number[j] == Number[i]) && (j < i)))) { /* nothing */ }



     }



 }



 unlock(integer i) {



     Number[i] = 0;



 }



Does this algorithm implement spin lock correctly? WIll there be deadlocks? Explain the use of choosing and number arrays. What  may be potential issues with this algorithm when implemented on a real computer and how would you  fix them?
