struct _NODE

{

    int     Value;

    struct _NODE* Previous;

    struct _NODE* Next;

} NODE;


/*
Create a function Producer that will generate 100 random integer numbers, and share them with a function Consumer through a pipe. The Consumer function will then add those numbers to a linked list of NODEs. The consumer function executes in two threads concurrently and maintains the same linked list.
*/
int NUM;

void producer(void)
{
    /* Create a random number */
    int num = rand();
    /* Send num to customer */
    mutex_lock();
    NUM = num;
}

void consumer(int number)
{
    /* store in single value */
    if(mutex_lock()==true)
    {
        /* Push to linked list, includes malloc, adding node */
        addLL(NUM);
        /* Reset NUM */
        NUM=0;
    }
    mutex_unlock();
}

