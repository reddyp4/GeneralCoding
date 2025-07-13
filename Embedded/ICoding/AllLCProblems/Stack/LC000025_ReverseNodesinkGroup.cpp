/*
25. Reverse Nodes in k-Group
Solved
Hard
Topics
conpanies icon
Companies
Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.

 

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]
Example 2:


Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]
 

Constraints:

The number of nodes in the list is n.
1 <= k <= n <= 5000
0 <= Node.val <= 1000
 

Follow-up: Can you solve the problem in O(1) extra memory space?
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 /*
M1: Push k-elements into stack, save head
    As pop, update next
    Seperately get the count?
    Needs space O(k)-stack
M2: O(1) space, means no stack -> need a pointer?
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL)  return head;
        if(k==1)    return head;
        stack<ListNode*> myStk;
        ListNode *node=head,*nexthead,*newhead,*prevtail;
        bool first=true,possible=true,print=false;
        int i=0,j=0;
        /* First time, need to update head */
        while(possible) {
            if(print)   cout<<"Current Node:"<<node->val<<endl<<"Push:";
            i=0;
            while(node!=NULL && i<k)    {
                if(print)   cout<<node->val<<",";
                i++;myStk.push(node);node=node->next;
            }
            if(print)   cout<<endl;
            if(print)   cout<<"i:"<<i<<",k:"<<k<<endl;
            if(i<k) {possible=false;break;}
            nexthead=node;    //hold the next
            if(print)   cout<<"nexthead:"<<nexthead->val<<endl;
            if(first)   {newhead=myStk.top();node=newhead;myStk.pop();}
            else    node=prevtail;
            first=false;
            if(print)   cout<<"Pop:";
            while(!myStk.empty())   {
                if(print)   cout<<node->val<<",";
                node->next=myStk.top();node=node->next;myStk.pop();
            }
            prevtail=node;
            //Stich back
            node->next=nexthead;
            if(print)   cout<<node->val<<","<<"temp:"<<prevtail->val<<endl;
            //update node
            node=nexthead;
        }
        return newhead;
    }
};

/*
Runtime
3
ms
Beats
4.04%
Analyze Complexity
Memory
16.93
MB
Beats
5.78%
*/