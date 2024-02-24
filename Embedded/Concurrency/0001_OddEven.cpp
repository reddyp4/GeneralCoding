/*
Odd Even Problem: (mutex and cv)

Create two threads. Let one thread print odd numbers and other, even numbers.
Assume natural numbers (1,2,3...) from 1 to 100

Numbers must be printed in natural order
Use a mutex and a cv
*/

int count = 1;
Lock mutex = new ReentrantLock();
Condition isEven = mutex.newCondition();
Condition isOdd = mutex.newCondition();

void odd()
{
    mutex.lock();   //Wait for lock
    while(count<=100)
    {
        while(count%2==0) { //if you use "if", can lead to spurious walking, wait here for even
            isOdd.await();  //wait for isOdd
        }
        count << count << endl;
        count++;
        isEven.signal();    //signal the next function
    }
}

void  even()
{
    mutex.wait();   //wait for lock
    while(count<=100) {
        while(count%2!=0){  //if count is odd, wait; while instead of if, for spurious walkng
            isEven.wait();  //go to wait state
        }
        cout << count;
        count++;
        isOdd.signal();     //signal the odd function
    }
}

Thread oddThread = new Thread(odd);
Thread evenThread = new Thread(even);

oddThread.start();
evenThread.start();

/*
Basic functionality:
wait for lock
check condition and print->usual but spurious walking of cv
so count is odd, and we are in even, go to wait, and wait for signal from other
*/