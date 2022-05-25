//Linked List Node
#include <stdio.h>
#include <stdlib.h>

typedef struct node_str
{
    int data;
    struct node_str* next;
} str_node;

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

/* Linked List functions, add, remove, print*/
int main(void)
{
    /*Create empty linked list*/
    str_node* head = (str_node*)malloc(sizeof(str_node));
    head->data=0;
    head->next=NULL;

    /*Add elements*/
    head = addLLElement(head,1);
    head = addLLElement(head,2);
    head = addLLElement(head,3);

    /*Print elements*/
    printLL(head);
    /*Remove elements*/
    // str_node* new = (str_node*)malloc(sizeof(str_node));
    int element = removeLLElement(head);
    printf("value removed:%d\n",element);

    /*Print elements*/
    printLL(head);
}