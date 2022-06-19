'''
BFS:
Part 1: BFS
Level Order Traversal of a Binary Tree
Zigzag Order Traversal of a Binary Tree
'''
from contextlib import nullcontext
from logging import root
from typing import List
from unittest import result

Queue Q1

#Lever Order Traversal
def printDFS(root: List[int]):
    result = new List()

    if(root isn null) return result

    Q1.newQueue()
    
    nodeQ.add(root)

    while(nodeQ!=empty):
        int count = nodeQ.size()
        temp = new List()
        
        for i in range(0,count):
            treenode node = nodeQ.remove()

            temp.add(node.val)

            if(node.left is not null) nodeQ.add(node.left)
            if(node.right is not null) nodeQ.add(node.right)
        result.add(temp)
    
    return result
