'''
Balanced BST From A Sorted Array
Given a sorted list of distinct integers, build a balanced binary search tree (BST).

A BST is called balanced if the number of nodes in the left and right subtrees of every node differs by at most one.

Example
{
"a": [8, 10, 12, 15, 16, 20, 25]
}
Output:

Example Output

Notes
You have to return the root of the balanced BST that you created.
There can be multiple balanced BST for given input. So, you are free to return any of the valid one.
Constraints:

-2 * 109 <= value in the given list <= 2 * 209
1 <= size of the given list <= 105
'''

'''
Solution method here:
Get index of mid-element
Pick the mid-element
define root
call recursive on left, return pointer to node, assign to left
call recursive on right, return pointer to node, assign to right

base case: if two elements: one left and one right
base case: if one element, put on left
'''


"""
For your reference:
class BinaryTreeNode:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None
"""
from typing import List

class BinaryTreeNode:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

def bst_helper(a:list[int]) -> BinaryTreeNode:
    # Base case, empty list
    if not a:
        return None
    if(len(a)==1):  #single element
        return BinaryTreeNode(a)
    #identify the mid-index
    mid_index = int(len(a)/2)
    root = BinaryTreeNode(a[mid_index])
    #call helper on left and assign the node value to left
    root.left = bst_helper(a[0:mid_index-1])
    root.right = bst_helper(a[mid_index+1:len(a)])
    return root

def build_balanced_bst(a:List[int]) -> BinaryTreeNode:
    """
    Args:
     a(list_int32)
    Returns:
     BinaryTreeNode_int32
    """
    # Write your code here.
    if not a:
        return None
    root = bst_helper(a)
    return root

a= [8, 10, 12, 15, 16, 20, 25]
root = build_balanced_bst(a)
