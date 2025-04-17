/*
19. Remove Nth Node From End of List
Solved
Medium
Topics
Companies
Hint
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
            //search for (n+1) node from end
            if((head==NULL) || (head->next==NULL && n==1)) return NULL;
            //Single pass solution
            int cnt=1;
            ListNode *prev_node=head,*nodeend=head;
            while(nodeend->next!=NULL && cnt<=n) //prev node 
            {
                cnt++;nodeend=nodeend->next;
            }
            cout<<cnt<<","<<(nodeend->val)<<","<<endl;
            if(cnt<n)   return head;    //nodes#<n
            if(cnt==(n) && (nodeend->next)==NULL)  //reached end, count not reached n+1, ex: 2 nodes, n=2, cannot reach cnt==3 remove head
                return head->next;
            // if we are here, we have #nodes>n
            while(nodeend->next!=NULL)
            {
                nodeend=nodeend->next;prev_node=prev_node->next;
            }
            if(prev_node==head)    return head->next;
            cout<<prev_node->val<<","<<nodeend->val<<","<<endl;
            //remove node
            prev_node->next=(prev_node->next)->next;
            //free(node);
            return head;
        }
    };

/*
To be added:

*/