//Linked List Node
#include <stdio.h>
#include <stdlib.h>

typedef struct node_str
{
    int data;
    struct node_str* next;
} str_node;

/*Create linked list */
str_node* createLL(int* array, int n)
{
    int i;
    str_node *node, *last, *head;
    head = (str_node*)malloc(sizeof(str_node));
    head->data = *array;
    head->next = NULL;
    printf("%d, ", head->data);

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
        printf("%d, ",p->data);
        p=p->next;
    }
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

/*Remove element*/
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
}

/* Linked List functions, add, remove, print*/
int main(void)
{
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
    if(pSearch)
        printf("Value found %d\n",pSearch->data);
    else
        printf("Value not found!\n");
    printf("Printing recursively, after moving the found key %d\n ",pSearch->data);
    printLL(head);
    
    /*
    str_node* pSearchRec = searchLLRecur(head,key);
    if(pSearchRec)
        printf("Value found %d\n",pSearchRec->data);
    else
        printf("Value not found!\n");
    printLLRecur(head);*/
}
