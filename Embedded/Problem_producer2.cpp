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

semphore s
conditional variable cv
mutex m     // on num
int num[100]={0};


void producer(void)
    m.acquire()
    if(num.isFull)  wait(cv,m)
    push(num,rand())
    if(sizeof(num)>1)   signal(cv)
    m.release()

/* For multiple threads calling consumer, need a semaphore instead of a mutex? */
void consumer(int number)
    m.acquire()
    if(num.isEmpty) wait(cv,m)
    addtoLL(pop(num))
    if(sizeof(num)<=MAX)    signal(cv)
    m.release()

