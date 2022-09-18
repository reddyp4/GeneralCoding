Consider the following two threads A and B which update the values of shared variables ‘a’ and ‘b’.



void ThreaD_A () {

// Do some internal operations;

	a = a*b;

	b++;

	// Do Some more internal processing

}



void ThreaD_B () {

// Do some internal operations;

	a++;

	b = a*b;

	// Do Some more internal processing

}



int main(void) {

int a, b;

a = 2;

b = 3;

	OS_CreateThread(Thread_A, …);

	OS_CreateThread(Thread_B, …);

	While (1);

}



If Thread A and Thread B executed sequentially, the values of ‘a’ and ‘b’ will be calculated in the following manner:



1. a= a*b = 2*3 = 6 /* Thread A */

2. b ++ = 3+1 = 4 /* Thread A */

3. a++ = 6+1 = 7  /* Thread B */

4. a*b = 4*7 = 28 /* Thread B */

 a = 7, b=28







Part-A: Write an interleaved concurrent execution order for the two threads that gives the same output as the sequential execution.



Part-B: Write an interleaved concurrent execution order that may give a different value than the sequential execution.
