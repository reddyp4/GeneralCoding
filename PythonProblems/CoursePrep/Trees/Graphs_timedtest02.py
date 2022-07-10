"""
Create A Transpose Of A Directed Graph
Given a strongly connected directed graph, return its transpose. The graph will be given as a reference to one of its nodes; the rest of the graph can be discovered by walking its edges.

Example
Input: a node of a graph like this:

Input

Output: a node of a graph like this:

Output

Notes
Constraints:

1 <= number of nodes <= 315
Node values are unique integers, and 1 <= node value <= number of nodes
No multiple edges (connecting any pair of nodes in one direction) or self loops (edges connecting a node with itself) in the input graph
Description of the text format of the test cases

You might need this for debugging your solution on IK UpLevel platform.

Input and output file each contain a list or directed edges representing a directed graph.

The input example

Example

is represented by

{
"edges": [
[1, 2],
[2, 3],
[3, 1]
]
}
and the output

Output

is represented by

[
[2, 1],
[3, 2],
[1, 3]
]
"""

"""
For your reference:
class GraphNode:
    def __init__(self, value):
        self.value = value
        self.neighbors = []
"""
def create_transpose(node):
    """
    Args:
     node(GraphNode_int32)
    Returns:
     GraphNode_int32
    """
    # Write your code here.
    return node
