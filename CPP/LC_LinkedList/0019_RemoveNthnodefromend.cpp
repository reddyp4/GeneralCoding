/* 
19. Remove Nth Node From End of List
Medium
15.6K
656
company
Google
company
Amazon
company
Apple
Given the head of a linked list, remove the nth node from the end of the list and return its head.

 

Example 1:


Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:

Input: head = [1], n = 1
Output: []
Example 3:

Input: head = [1,2], n = 1
Output: [1]
 

Constraints:

The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz
 

Follow up: Could you do this in one pass?
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        /* M1: Have head+n ptr. Wait until this reaches end. Maintain prev */
        /* Cornercase, removing head. Beats T(39%),S(75%)*/
        if(!head || !head->next)   return nullptr;
        struct ListNode *node = new ListNode(), *prev = new ListNode();
        node = head, prev->next=head;
        int count=1;
        while(count<n)
        {
            node=node->next;
            count=count+1;
        }
        while(node->next)
        {
            prev=prev->next;
            node=node->next;
        }
        if(prev->next==head)
        {
            /* Remove head*/
            prev->next = prev->next->next;
            return prev->next;
        }
        else
        {
            prev->next = prev->next->next;
            return head;
        }
    }
};