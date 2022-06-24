'''
Kth Smallest Element Of BST
Given a binary search tree (BST) and an integer k, find k-th smallest element.

Example
Example one

k = 3

Output:

3
The 3rd smallest element is 3.

Notes
There are two arguments in the input. First one is the root of the BST and second one is an integer k.
Return an integer, the k-th smallest element of the BST.
Constraints:

1 <= number of nodes in the BST <= 6000
1 <= k <= number of nodes
-2 * 109 <= value stored in any node <= 2 * 109
You are not allowed to alter the given BST in any way.
'''

"""
For your reference:
class BinaryTreeNode:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None
"""

"""
Idea: Do the inorder traversal, maitain count
once count reaches k, return
return the kth element
"""

class BinaryTreeNode:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

def k_smallest_helper(root:BinaryTreeNode, count:int, k:int, final:int):
    #Base case
    if(root is None):
        return 0
    #reached count = k
    if(count==k):
        final= root.value
        return
    else:
        #if left, then continue, if not stop
        if(root.left is None):
            return
        #left traversal
        k_smallest_helper(root.left,count,k,final)
        count=count+1
        #if right, then continue, if not stop
        if(root.right is None):
            return
        k_smallest_helper(root,count,k,final)
    return 

def kth_smallest_element(root:BinaryTreeNode, k:int):
    """
    Args:
     root(BinaryTreeNode_int32)
     k(int32)
    Returns:
     int32
    """
    # Write your code here.
    if(root is None):
        return 0    #error code
    #Use recursion?
    #traverse left first
    final=0
    k_smallest_helper(root,0,k,final)
    return final


root = [2, 1, 3]
k= 3
final=kth_smallest_element(root,k)
print(final)

