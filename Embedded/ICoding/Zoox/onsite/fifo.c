/* https://leetcode.com/problems/design-circular-queue/ */

class MyCircularQueue {
public:
    //Queue, , insert at head, remove at tail
    int *myQ;
    int head,tail,size;
    bool isFULL;
    bool print;
    MyCircularQueue(int k) {
        size=k;
        head=tail=0;    //initially head=tail, isFULL seperates this condn
        isFULL=false;
        myQ = new int[k];
        print=false;
    }
    
    bool enQueue(int value) {
        //if full, no overwrite
        if(isFull())    return false;
        //add at head, and update
        myQ[head]=value;
        head=(head+1)%size;
        if(head==tail)  isFULL=true;
        if(print)   cout<<"enq:head:"<<head<<",tail:"<<tail<<",isFULL:"<<isFULL<<endl;
        return true;
    }
    
    bool deQueue() {
        //remove at tail, if empty return false
        if(isEmpty())   return false;
        tail=(tail+1)%size;
        if(size!=1 && head!=tail)  isFULL=false;
        else isFULL=false;
        if(print)   cout<<"deq:head:"<<head<<",tail:"<<tail<<",isFULL:"<<isFULL<<endl;
        return true;
    }
    
    int Front() {
        if(isEmpty())    return -1;
        if(print)   cout<<"fron:head:"<<head<<",tail:"<<tail<<",isFULL:"<<isFULL<<endl;
        //if(tail==0) return myQ[size-1];
        return myQ[tail];
    }
    
    int Rear() {
        if(isEmpty())    return -1;
        if(print)   cout<<"rear:head:"<<head<<",tail:"<<tail<<",isFULL:"<<isFULL<<endl;
        if(head==0) return myQ[size-1];
        return myQ[head-1];
    }
    
    bool isEmpty() {
        if(size==0) return true;
        if(print)   cout<<"isemp:head:"<<head<<",tail:"<<tail<<",isFULL:"<<isFULL<<endl;
        if(head==tail && isFULL==false) return true;
        return false;
    }
    
    bool isFull() {
        //check variable
        return(isFULL);
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