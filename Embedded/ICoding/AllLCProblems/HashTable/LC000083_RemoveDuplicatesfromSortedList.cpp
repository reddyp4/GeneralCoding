/*
83. Remove Duplicates from Sorted List
Solved
Easy
Topics
conpanies icon
Companies
Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.

 

Example 1:


Input: head = [1,1,2]
Output: [1,2]
Example 2:


Input: head = [1,1,2,3,3]
Output: [1,2,3]
 

Constraints:

The number of nodes in the list is in the range [0, 300].
-100 <= Node.val <= 100
The list is guaranteed to be sorted in ascending order.
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
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        /* HASH-MAP */
        /*if(head==NULL || head->next==NULL)  return head;
        unordered_map<int,bool> myMap;
        ListNode *node=head;
        myMap[node->val]=true;
        while(node!=NULL && node->next!=NULL)   {
            //cout<<","<<node->next->val;
            while(node->next && myMap.count(node->next->val))    node->next=node->next->next;
            if(node->next) myMap[node->next->val]=true;
            node=node->next;
        }
        if(node!=NULL && myMap.count(node->val)>0)    node=NULL;
        return head;*/
        /* Since sorted compare to next node */
        if(head==NULL || head->next==NULL)  return head;
        ListNode *node=head;
        while(node!=NULL && node->next!=NULL) {
            while(node->next && node->val==node->next->val) node->next=node->next->next;
            node=node->next;
        }
        return head;
    }
    }
};

/*
Runtime
0
ms
Beats
100.00%
Analyze Complexity
Memory
16.77
MB
Beats
5.28%

Simple check
Runtime
0
ms
Beats
100.00%
Analyze Complexity
Memory
16.11
MB
Beats
69.18%

*/