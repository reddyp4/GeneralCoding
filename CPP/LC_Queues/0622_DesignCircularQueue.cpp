class MyCircularQueue {
    int *myQ;
    int head;
    int tail;
    int size;

public:
    MyCircularQueue(int k) {
        size=k;
        head=tail=-1;
        myQ=new int[k];
    }
    
    bool enQueue(int value) {
        /* Check if not full, Increment and add at head, if space */
        if(isFull())    return false;
        if(head==-1)
        {
            myQ[0]=value;
            head=tail=0;
            return true;
        }
        /* Increment head, with wrap */
        head = (head++)%size;
        myQ[head]=value;
        return true;
    }
    
    bool deQueue() {
        /* Check if buffer is empty, else increment tail */
        if(isEmpty())    return false;
        tail = (tail++)%size;
        /* If empty, after removing, reset */
        if(tail-head==1)
        {
            head=-1;
            tail=-1;
        }
        return true;
    }
    
    int Front() {
        if(isEmpty())   return -1;
        return myQ[head];
    }
    
    int Rear() {
        if(isEmpty())    return false;
        return myQ[tail];
    }
    
    bool isEmpty() {
        return(head==-1);        
    }
    
    bool isFull() {
        return( (tail-head==1) || (head==size-1 && tail==0) );
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */