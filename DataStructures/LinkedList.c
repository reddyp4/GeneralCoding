//Linked List Node
#include <stdio.h>
#include <stdlib.h>

struct linkedlist
{
    int data;
    struct linkedlist* next;
};

struct linkedlist* addLLElement(struct linkedlist* node, int data)
{
    struct linkedlist* new= (struct linkedlist*)malloc(sizeof(struct linkedlist));
    new->data = data;
    new->next = node;
    return new;
}

/*Print elements of linked list*/
void printLL(struct linkedlist* head)
{
    struct linkedlist* node = head;
    printf("Data:");
    while(node->next!=NULL)
    {
        printf("%d,",node->data);
        node=node->next;
    }
    printf("%d\n",node->data);
}

/*Remove element*/
int removeLLElement(struct linkedlist* head,struct linkedlist* newHead)
{
    int value = head->data;
    newHead->next = head->next;

    return value;
}

/* Linked List functions, add, remove, print*/
int main(void)
{
    /*Create empty linked list*/
    struct linkedlist* tail = (struct linkedlist*)malloc(sizeof(struct linkedlist));
    tail->data=0;
    tail->next=NULL;

    /*Add elements*/
    struct linkedlist* first = addLLElement(tail,1);
    struct linkedlist* second = addLLElement(first,2);
    struct linkedlist* third = addLLElement(second,3);

    /*Print elements*/
    printLL(third);
    /*Remove elements*/

    struct linkedlist* new = (struct linkedlist*)malloc(sizeof(struct linkedlist));
    int element = removeLLElement(third,new);
    printf("value removed:%d\n",element);

    /*Print elements*/
    printLL(new);
}