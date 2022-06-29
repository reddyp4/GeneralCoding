"""
Merge K Sorted Linked Lists

Given k linked lists where each one is sorted in the ascending order, merge all of them into a single sorted linked list.

Example
{
"lists": [
[1, 3, 5],
[3, 4],
[7]
]
}
Output:

[1, 3, 3, 4, 5, 7]
Notes
Constraints:

0 <= k <= 104
0 <= length of any given linked list <= 103
-109 <= node values <= 109
Sum of the lengths of all given lists won't exceed 105.
"""


"""
For your reference:
class LinkedListNode:
    def __init__(self, value):
        self.value = value
        self.next = None
"""

"""
Approach1: Pointers for each and until reach the end
Approach2: Go to end?
"""

class LinkedListNode:
    def __init__(self, value):
        self.value = value
        self.next = None

def merge_k_lists(lists):
    """
    Args:
     lists(list_LinkedListNode_int32)
    Returns:
     LinkedListNode_int32
    """
    # Write your code here.
    indices=[0 for x in range(len(lists))]
    final=[]
    k=0
    for i in range(len(lists)):
        for j in range(len(lists)):
            arr[j]=lists[i].
        #pick the min of new array of elements
    print(f"indices:{len(indices)}")
    return None

lists= [[1, 3, 5],[3, 4],[7]]
final=merge_k_lists(lists)
print(f"final={final}")
