/*
86. Partition List
Solved
Medium
Topics
conpanies iconCompanies

Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

 

Example 1:

Input: head = [1,4,3,2,5,2], x = 3
Output: [1,2,2,4,3,5]

Example 2:

Input: head = [2,1], x = 2
Output: [1,2]

 

Constraints:

    The number of nodes in the list is in the range [0, 200].
    -100 <= Node.val <= 100
    -200 <= x <= 200


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
M1: FinalHead
    LessHead
    MoreHead
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL)  return head;
        ListNode LessHead,*LessNode,MoreHead,*MoreNode,*node;
        LessNode=&LessHead;
        MoreNode=&MoreHead;
        node=head;
        bool print=false;
        if(print)   cout<<"Node:";
        while(node!=NULL)   {
            if(print)   cout<<node->val<<","<<endl;
            if(node->val<x) {
                LessNode->next=node;
                LessNode=LessNode->next;
                if(print)   cout<<"LessNode:"<<LessNode->val<<","<<endl;
            }
            else    {
                MoreNode->next=node;
                MoreNode=MoreNode->next;
                if(print)   cout<<"MoreNode:"<<MoreNode->val<<","<<endl;
            }
            node=node->next;
        }
        MoreNode->next=NULL;
        if(print)   cout<<endl;
        if(print)   cout<<"LessNode:"<<LessNode->val<<","<<endl;
        if(print)   cout<<"MoreHead.next:"<<(MoreHead.next)->val<<","<<endl;
        if(print)   cout<<"LessHead.next:"<<(LessHead.next)->val<<","<<endl;
        LessNode->next=MoreHead.next;
        node=LessHead.next;
        while(node!=NULL)   {
            if(print)   cout<<node->val<<",";
            node=node->next;
        }
        return (LessHead.next);
    }
};

/*
Runtime
0ms
Beats100.00%
Analyze Complexity
Memory
14.96MB
Beats46.04%
*/