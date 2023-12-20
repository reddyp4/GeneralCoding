'''
23. Merge k Sorted Lists
Hard
18.7K
676
company
Facebook
company
TikTok
company
Amazon
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

 

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
Example 2:

Input: lists = []
Output: []
Example 3:

Input: lists = [[]]
Output: []
 

Constraints:

k == lists.length
0 <= k <= 104
0 <= lists[i].length <= 500
-104 <= lists[i][j] <= 104
lists[i] is sorted in ascending order.
The sum of lists[i].length will not exceed 104.
'''
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        if(lists is None):
            return None
        dummy = ListNode(0)
        ll = dummy
        k=len(lists)
        if(k==0):
            return None
        d={}
        llval=[]
        for index in range(k):
            d[index]=lists[index]
            if(lists[index] is None):
                llval.append(100000)
            else:
                llval.append(d[index].val)
        newmin = min(llval)
        while(newmin!=100000):
            #Get new min
            llvalIndex = llval.index(newmin)
            #move it to ll
            ll.next = d[llvalIndex]
            #remove the node
            d[llvalIndex]=d[llvalIndex].next
            lists[llvalIndex] = lists[llvalIndex].next
            #refill the index for llvals
            if(d[llvalIndex]):
                llval[llvalIndex]=d[llvalIndex].val
            else:
                llval[llvalIndex]=100000
            #move ll
            ll = ll.next
            newmin = min(llval)
        ll.next = None
        return dummy.next

'''
Too concise solution:
class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        if not lists:
            return None
        if len(lists) == 1:
            return lists[0]
        mid = len(lists) // 2
        left = self.mergeKLists(lists[:mid])
        right = self.mergeKLists(lists[mid:])
        return self.merge(left, right)

    def merge(self, l1, l2):
        dummy = ListNode(0)
        curr = dummy
        while l1 and l2:
            if l1.val < l2.val:
                curr.next = l1
                l1 = l1.next
            else:
                curr.next = l2
                l2 = l2.next
            curr = curr.next
        curr.next = l1 or l2
        return dummy.next
'''

'''

'''