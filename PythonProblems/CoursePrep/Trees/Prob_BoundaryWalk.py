'''
Boundary Walk (Depth-first, Recursion)

Handle an empty tree as a special edge case

Create a recursive function to execture on every node

Function: dfs(node)
Base Case: If leaf node then do something if necessary
Recursive case: Not a leaf node

Pre-order:
Process info before visiting each child
If node has a left child: dfs(node.left)

In-order
Process the information in sequence
If node has a right child, dfs(node.right)

Post-order:
Process information after both children are visited

'''
