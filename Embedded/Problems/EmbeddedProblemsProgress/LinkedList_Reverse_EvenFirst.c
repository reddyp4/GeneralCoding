// Compiled with: gcc -std=c11 -Wall -pthread -lm

#include <stdio.h>
#include <stdint.h>

/*

 bit 
 
 
 uint64_t x = 0xface0000ULL;
 find longest continue number of one: return length
 
 
    11110001110000011111
    4.      3.     5
    
    return 5


reverse linklist

    1 2 3 4 2
    4 2 3 2 1 =just rev
    2 4 2 3 1 =rev and even at beginning (correct answer)
    evenhead = 2 4 2
    oddhead = 3 1
    
    oddhead = 1, dummy=1, current=3
    oddhead->next = 3
    current=4
    oddhead->next->next = 1 (dummy)
    
    
    evenend->oddhead
    
    2 4 2 3 1. (even before odd numbers)
    
    
    
    2 4 3 1 1 1
    
    
    return  4 2 1 1 1 3
*/
// O(1) extra space
// no recursion
// look for one pass solution

Node * reverse(Node* head) {
    Node *evenhead=NULL, *oddhead=NULL, *evenend=NULL, *current;
    int flag=0;
    current=head;
    while(current!=NULL)
    {
        Node * next = current->next;
        if(current->val%2 == 0)
        {
            if (evenend == NULL)
            {
                evenend= current;
    
            }
            //even node, attach in between evenhead and next node
            current->next = evenhead;
            evenhead = current;  

        }
        else
        {
            current->next = oddhead;
            oddhead = current;
            
        }
        current = next;
    }
    if(evenend!=NULL)
    {
        evenend->next=oddhead;
        return evenhead;
    }
    return oddhead;
}


Node * reverse2(Node* head) {
    Node *evenhead=NULL, *oddhead=NULL, *evenend=NULL, *current, *dummy;
    int flag=0;
    current=head;
    while(current!=NULL)
    {
        if(current->val%2 == 0)
        {
            //even node, attach in between evenhead and next node
            dummy=evenhead->next;
            evenhead->next = current;
            current=current->next;
            evenhead->next->next = dummy;
            if(flag==0)
            {
                //ptr to end of even LL
                evenend=evenhead->next;
                flag=1;
            }
        }
        else
        {
            //odd node
            dummy=oddhead->next;
            oddhead->next = current;
            current=current->next;
            oddhead->next->next = dummy;
        }
    }
    if(evenend!=NULL)
    {
        evenend->next=oddhead;
        return evenhead;
    }
    return oddhead;
}