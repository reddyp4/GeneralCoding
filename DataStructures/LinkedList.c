//Linked List Node
#include <stdio.h>
#include <stdlib.h>

typedef struct node_str
{
    int data;
    struct node_str* next;
} str_node;

str_node *first;    

/*Create linked list */
str_node* createLL(int* array, int n)
{
    int i;
    str_node *node, *last, *head;
    head = (str_node*)malloc(sizeof(str_node));
    head->data = *array;
    head->next = NULL;
    printf("Creating LL: %d, ", head->data);

    /*Start adding nodes*/
    last = head;
    for(i=1;i<n;i++)
    {
        /*Create new node*/
        node = (str_node*)malloc(sizeof(str_node));
        /*Populate the new node*/
        node->data=*(array+i);
        node->next = NULL;
        printf("%d, ", node->data);

        /*Add it to the LL*/
        last->next = node;

        /*Move the last pointer*/
        last = node;
    }
    last = NULL;
    printf("\n");

    return head;
}

str_node* addLLElement(str_node* node, int data)
{
    //Add element at head
    //Declare the address variable in heap
    str_node* p = (str_node*)malloc(sizeof(str_node));
    //Assign the pointer correctly
    p->next = node;
    p->data = data;
    return p;
}

/*Print elements of linked list*/
void printLL(str_node* head)
{
    str_node* p;
    p=head;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

/*Print elements recursively of linked list*/
void printLLRecur(str_node* head)
{
    if(head!=NULL)
    {
        printf("%d, ",head->data);
        printLLRecur(head->next);
    }
}

/*Remove tail element*/
int removeLLElement(str_node* head)
{
    //Assume element removed at tail - FIFO
    str_node* tail = head;
    while(tail->next->next!=NULL)
    {
        tail=tail->next;
    }
    //reached the last but one element
    int val = tail->next->data;
    tail->next=NULL;
    return val;
}

/*Count the node*/
int countLL(str_node* head)
{
    int count=0;
    str_node* p=head;
    while(p!=NULL)
    {
        p=p->next;
        count++;
    }
    return count;
}

/*Get max of LL*/
int MIN_INT = -32768;
int maxLL(str_node* head)
{
    int max=MIN_INT;
    str_node* p=head;
    while(p!=0)
    {
        if(max<p->data)
        {
            max=p->data;
        }
        p=p->next;
    }
    return max;
}
int maxLLRecur(str_node* head)
{
    static int max;
    max=MIN_INT;
    if(head==0)
        return MIN_INT;
    int val= maxLLRecur(head->next);
    max = head->data > val ? head->data : val;
    return max;
}

/*Linear Search*/
str_node* searchLL(str_node* head, int key)
{
    /*Move value to header*/
    str_node* p;
    str_node* q;
    p = head;
    q = head;
    while(p!=0)
    {
        if(key==p->data)
        {
            q->next = p->next;
            p->next = head;
            head = p;
            return p;
        }
        q = p;
        p=p->next;
    }
    return NULL;
}
/*Recursive Search*/
str_node* searchLLRecur(str_node* head,int key)
{
    if(head!=NULL)
    {
        if(head->data==key)
            return head;
        else
            return searchLLRecur(head->next,key);
    }
    return NULL;
}

/*Insert at head - LIFO*/
str_node* insertLLHead(str_node* head, int val)
{
    str_node* p = (str_node*)malloc(sizeof(str_node));
    p->data=val;
    p->next=head;
    return p;
}

/*Insert at position n*/
str_node* insertLLPOS(str_node* head,int pos, int val)
{
    /*Insert after position, starts from 1*/
    str_node* p=(str_node*)malloc(sizeof(str_node));
    str_node* q=head;
    int count=1;
    /*Move until position*/
    printf("Moving q: ");
    while(count<pos)
    {
        q=q->next;
        count++;
        printf("%d ",q->data);
    }
    printf("\n");
    /*Insert after p*/
    p->data=val;
    p->next=q->next;
    q->next=p;
    if(count==0)
        return q;
    else
    {
        return head;
    }
}

str_node* findLLLast(str_node* head)
{
    str_node* p =head;
    while(p->next!=NULL)
        p=p->next;
    return p;
}

str_node* insertLLLast(str_node* last, int val)
{
    str_node* p = (str_node*)malloc(sizeof(str_node));
    p->data = val;
    p->next = NULL;
    last->next = p;
    last = p;
    return last;
}

/*Inset in sorted linked list*/
str_node* insertLLSorted(str_node* head, int val)
{
    str_node* p = (str_node*)malloc(sizeof(str_node));
    p->data=val;
    p->next=NULL;
    /*Corner case of head>val*/
    if(head->data>val)
    {
        p->next=head;
        printf("Came here!");
        return p;
    }
    /*Find location of q, where p should be inserted*/
    str_node *q=head;
    while(q->next!=NULL)
    {
        if(q->next->data>val)
            break;
        q=q->next;
    }
    p->next=q->next;
    q->next=p;

    return head;
}

/*Check if linked list if sorted*/
int checkLLSorted(str_node* head)
{
    str_node* p=head;
    while(p->next!=NULL)
    {
        if(p->next->data<p->data)
        {
            return 0;
        }
        p=p->next;
    }
    return 1;
}

/*Delete element at position n*/
str_node* deleteLLElement(str_node* head, int pos)
{
    str_node* p = head;
    int count=1;
    while(count+1<pos)
    {
        p=p->next;
        count++;
    }
    /*If first element, update head, other update node at p*/
    if(pos==1)
    {
        p=p->next;
        return p;
    }
    else
    {
        p->next=p->next->next;
        return head;
    }
}

/* Linked List functions, remove duplicates*/
str_node* removeDuplicates(str_node* head)
{
    str_node* q =head->next;
    str_node* p = head;
    while(q!=NULL)
    {
        if(p->data==q->data)
        {
            /*Found duplicate, remove q*/
            p->next=q->next;
            free(q);
        }
        /* Just move*/
        p=p->next;
        q=q->next;
    }
    return head;
}

/*Reverse linked list with three sliding pointers*/
/* Idea is to have three sliding pointers, r, q, p */
/* r=q, q=p, p=p->next*/
/* q->head will be r after assignment of three pointers */
/* Do while p!=NULL*/
str_node* reverseLL(str_node* head)
{
    str_node *p,*q,*r;
    p=head;
    q=NULL;
    r=NULL;
    while(p!=NULL)
    {
        /*Sliding pointers*/
        r=q;
        q=p;
        p=p->next;
        /*Swap q,r: prev r.next->q: new q.next=r*/
        q->next=r;
    }
    return q;
}

/* Reverse LL recursively */
/* Idea is that p(tail),q, are returned by recursion*/
/* Sliding pointers: head(moves by next), tail returned by recursion */
void reverseLLRecur(str_node* head, str_node* tail)
{
    /*check if head is null*/
    if(head->next!=NULL)
    {
        reverseLLRecur(head->next,tail->next);
        head->next=tail;
        //tail = head;
    }
    else
    {
        first = (str_node*)malloc(sizeof(str_node));
        first->next=tail;
        first=head;
    }
}

/* Linked List functions, add, remove, print*/
int main(void)
{

#if 0
#if 0 //For initial code, adding element by element
    /*Create empty linked list*/
    str_node* head = (str_node*)malloc(sizeof(str_node));
    head->data=0;
    head->next=NULL;

    /*Add individual elements*/
    head = addLLElement(head,1);
    head = addLLElement(head,8);
    head = addLLElement(head,3);
    head = addLLElement(head,14);
    head = addLLElement(head,7);
    head = addLLElement(head,12);
    head = addLLElement(head,9);
#endif
    /*Add all array at once*/
    int array[8] = {1,8,3,4,14,7,12,9};
    /*Create linkedlist, including head*/
    str_node* head = createLL(array,8);

    /*Print elements*/
    printf("\nPrinting LL: ");
    printLL(head);

#if 0
    /*Remove elements*/
    // str_node* new = (str_node*)malloc(sizeof(str_node));

    int element = removeLLElement(head);
    printf("value removed:%d\n",element);

    /*Print elements*/
    //printLL(head);

    /*Print recursively*/
    printf("Printing recursively: ");
    printLLRecur(head);

    /*Count*/
    printf("Size of LL = %d\n",countLL(head));

    /*Print max of LL*/
    printf("Max of LL = %d\n",maxLL(head));
    printf("Max of LL (recursively) = %d\n",maxLLRecur(head));
#endif

    int key = 12;
    /*Search for key*/
    str_node* pSearch = searchLL(head,key);
    head = pSearch;

    key = 9;
    /*Search for key*/
    pSearch = searchLL(head,key);
    head = pSearch;

    if(pSearch)
        printf("Value found %d\n",pSearch->data);
    else
        printf("Value not found!\n");
    printf("Printing recursively, after moving the found key %d\n ",pSearch->data);
    printLL(head);
    
#if 0
    str_node* pSearchRec = searchLLRecur(head,key);
    if(pSearchRec)
        printf("Value found %d\n",pSearchRec->data);
    else
        printf("Value not found!\n");
    printLLRecur(head);
#endif
    /*Insert at head*/
    head = insertLLHead(head,5);
    printLL(head);

    /*Insert at position3*/
    printLL(head);
    head = insertLLPOS(head,3,6);
    printLL(head);

    /*Find last and insert*/
    str_node* last = findLLLast(head);
    key=20;
    last = insertLLLast(last,key);
    /*Print LL*/
    printLL(head);
#endif

    /*Sorted Linked List*/
    int sortedArr[5] = {10,20,30,40,50};
    str_node* sorted = createLL(sortedArr,5);
    sorted = insertLLSorted(sorted,25);
    printf("Adding element %d to sorted LL\n",25);
    printLL(sorted);
    sorted = insertLLSorted(sorted,55);
    printf("Adding element %d to sorted LL\n",55);
    printLL(sorted);
    sorted = insertLLSorted(sorted,5);
    printf("Adding element %d to sorted LL\n",5);
    printLL(sorted);

    /*Check if list is sorted*/
    printf("Linklist is sorted?: %d\n",(int)checkLLSorted(sorted));
    sorted = insertLLPOS(sorted,3,2);
    printLL(sorted);
    printf("Linklist is sorted?: %d\n",(int)checkLLSorted(sorted));
    /*Remove the unsorted element, 2 at position 3*/
    sorted = deleteLLElement(sorted,4);
    printLL(sorted);
    /*Add 20*/
    sorted = insertLLSorted(sorted,20);
    printf("Adding 20: ");
    printLL(sorted);
    /*Remove duplicates*/
    printf("Before duplicates: ");
    printLL(sorted);
    sorted = removeDuplicates(sorted);
    printf("After removing duplicates: ");
    printLL(sorted);

#if 0
    /*Reverse the linked list*/
    printf("Before reveral: ");
    printLL(sorted);
    sorted = reverseLL(sorted);
    printf("After reversal: ");
    printLL(sorted);
#endif

    /*Reverse the linked list recursively*/
    printf("Before reversal: ");
    printLL(sorted);
    reverseLLRecur(sorted->next,sorted);
    printf("After reversal: ");
    printLL(first);
}
