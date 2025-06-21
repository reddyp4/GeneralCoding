/*
24. Swap Nodes in Pairs
Solved
Medium
Topics
conpanies icon
Companies
Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

 

Example 1:

Input: head = [1,2,3,4]

Output: [2,1,4,3]

Explanation:



Example 2:

Input: head = []

Output: []

Example 3:

Input: head = [1]

Output: [1]

Example 4:

Input: head = [1,2,3]

Output: [2,1,3]

 

Constraints:

The number of nodes in the list is in the range [0, 100].
0 <= Node.val <= 100
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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL)  return head;
        ListNode *t1,*t2,*t3,*prev,*newhead;
        bool print=false;
        //get new head
        newhead=head->next;
        //get t1, t2, prev
        t1=head;
        t2=t1->next;
        t3=t2->next;
        prev=NULL;
        while(t1!=NULL && t2!=NULL)
        {
            if(print)
            {
                if(prev!=NULL)    cout<<"Old:prev:"<<prev->val;
                if(t1!=NULL)    cout<<",t1:"<<t1->val;
                if(t2!=NULL)    cout<<",t2:"<<t2->val;
                if(prev!=NULL)    cout<<",prev:"<<prev->val;
                cout<<endl;
            }
            if(prev!=NULL)      prev->next=t2;  //connect to previous nodes
            prev=t2->next;      //new prev
            t2->next=t1;        //reverse
            t1->next=t3;        //t1 to next
            if(t3==NULL)    break;  //end-condition
            //Update t1 and t2
            prev = t1;
            if(prev!=NULL)      t1 = prev->next;
            if(t1!=NULL)        t2=t1->next;
            if(t2!=NULL)        t3=t2->next;
            if(print)
            {
                if(prev!=NULL)    cout<<"End:prev:"<<prev->val;
                if(t1!=NULL)    cout<<",t1:"<<t1->val;
                if(t2!=NULL)    cout<<",t2:"<<t2->val;
                if(prev!=NULL)    cout<<",prev:"<<prev->val;
                cout<<endl;
            }
        }
        return newhead;
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
11.12MB
Beats
56.79%
*/