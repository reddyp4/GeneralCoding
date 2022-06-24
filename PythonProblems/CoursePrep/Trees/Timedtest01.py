'''
Height Of A Tree
Given a tree, find its height: number of edges in the longest path from the root to any node.

Example
Example

Output:

2
The longest path from the root is 1 -> 5 -> 4. It has two edges.

Notes
Return the number of edges in the longest path from the root to any node.
Constraints:

1 <= number of nodes <= 105

Idea:
maintain the height=0, and start there
if root is null, return height
Pass the count to both and left
for each child
get count
choose maximum of both
compare to height to maximum and choose the biggest

'''


"""
For your reference:
class TreeNode:
    def __init__(self, value):
        self.value = value
        self.children = []
"""

class TreeNode:
    def __init__(self, value):
        self.value = value
        self.children = []

def height_helper(root:TreeNode):
    height = 0
    #helper for height
    if(root.children is None):
        return 0
    #root has children
    size1=len(root.children)
    for index in range(0,size1):
        count = height_helper(root.children[index])+1
        height = height if height>count else count
    return height


def find_height(root:TreeNode):
    """
    Args:
     root(TreeNode_int32)
    Returns:
     int32
    """
    # Write your code here.
    height = 0
    #check if root is null
    if(root is None):
        return height
    #get children of root and push to que
    if(root.children is None):
        return height
    height = height_helper(root)
    return 0

testcase = 
{
"root": [1, null,
3, 2, 5, null,
null, null, 4]
}
