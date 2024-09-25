struct _NODE

{

    int     Value;

    struct _NODE* Previous;

    struct _NODE* Next;

} NODE;


/*
Create a function Producer that will generate 100 random integers, and share them with a function Consumer through a pipe. The Consumer function will then add those numbers to a linked list of NODEs.
*/


// use lock only

int num[100]={0};

producer:
    lock.acquire()
    while(num.isFull)  wait(cv,lock);
    num.push(rand())
    if(num.size>1): signal(cv)
    lock.release()

consumer:
    lock.acquire()
    while(num.isEmpty)  wait(cv,lock)
    addToLinkedList(num)
    if(num.size<=100)  signal(cv)   // producer must wakeup
    lock.release()

How does implmentation of wait look like?
wait(cv,lock):
    cv.push(threadid)
    release(lock)
    thread.yield() -> goes back to os sleep queue
    lock(lock)
    return

What does implementation of signal look like?
signal(cv):
    threadif = cv.pop()
    thread.run(threadid)


