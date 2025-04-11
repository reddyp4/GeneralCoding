/*
143. Reorder List
Solved
Medium
Topics
Companies
You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.

 

Example 1:


Input: head = [1,2,3,4]
Output: [1,4,2,3]
Example 2:


Input: head = [1,2,3,4,5]
Output: [1,5,2,4,3]
 

Constraints:

The number of nodes in the list is in the range [1, 5 * 104].
1 <= Node.val <= 1000


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
        void reorderList(ListNode* head) {
            stack<ListNode*> mystk;
            ListNode* node=head;
            ListNode* temp;
            if(head==NULL || head->next==NULL) return;
            int length=0,mid=0,i=1;
            while(node!=NULL)
            {
                length++;
                node=node->next;
            }
            mid=(int)((length+1)/2);
            node=head;
            while(i!=mid)
            {
                node=node->next;
                i++;
            }
            //cout<<mid;
            node=node->next;
            while(node!=NULL)
            {
                mystk.push(node);
                node=node->next;
            }
            node=head;
            while(mystk.size()!=0)
            {
                temp=node->next;
                //cout<<node->val;
                node->next=mystk.top();
                //cout<<mystk.top()->val;
                node->next->next=temp;
                node=temp;
                mystk.pop();
            }
            node->next=NULL;
            return;
        }
    };