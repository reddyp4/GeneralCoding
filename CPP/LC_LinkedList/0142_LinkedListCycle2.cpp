/*
142. Linked List Cycle II
Medium
11.5K
842
company
Amazon
company
Bloomberg
company
Microsoft
Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.

Do not modify the linked list.

 

Example 1:


Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.
Example 2:


Input: head = [1,2], pos = 0
Output: tail connects to node index 0
Explanation: There is a cycle in the linked list, where tail connects to the first node.
Example 3:


Input: head = [1], pos = -1
Output: no cycle
Explanation: There is no cycle in the linked list.
 

Constraints:

The number of the nodes in the list is in the range [0, 104].
-105 <= Node.val <= 105
pos is -1 or a valid index in the linked-list.
 

Follow up: Can you solve it using O(1) (i.e. constant) memory?
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        /*Method-1: Push address into set, if in set, return address */
        /* Beats: S(10%), T(11%)*/
        /*
        set<ListNode*> linkedAddr;
        ListNode* node=head;
        while(node && node->next)
        {
            if(linkedAddr.find(node)==linkedAddr.end())
            {
                linkedAddr.insert(node);
                node=node->next;
            }
            else    return node;
        }
        return NULL;*/
        /*Method-2: Push address into unordered_set, return address if already present */
        /* Beats: S(18%), T(17%)*/
        /*
        unordered_set<ListNode*> linkedAddr;
        ListNode* node=head;
        while(node && node->next)
        {
            if(linkedAddr.count(node)==0)
            {
                linkedAddr.insert(node);
                node=node->next;
            }
            else    return node;
        }
        return NULL;*/
        /*M3: Use slow/fast pointer to know if cycle exists and if not return NULL. 
        Now for distance, fast=2*slow speed, same disttane, 2*(f+a)=f+nc+a or f+a=nc, c=#nodes in cycle
        Now ptr1 start at intersection, ptr2 at head and meet again. Return meeting node. */
        /* Beats: Time(39%),Space(67%) */
        ListNode *slow=head, *fast=head;
        while(fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(fast==slow)  break;
        }
        if(fast==NULL or fast->next==NULL)  return NULL;
        while(head)
        {
            if(head==slow)  break;
            head=head->next;
            slow=slow->next;
        }
        return slow;
    }
};