'''
Code to create a binary tree

Treenode data structure
-val, left, right

Method1: Brute-force
Method2: Write a function to create BST given a sorted array

Idea is to create a library and import into other leetcode problems

'''

#Lets to method-1 first

from typing import List

#Python class to represent individual node
class Node:
    def __init__(self, value:int):
        self.val = value
        self.left = None
        self.right = None

#Print the children by level order traversal
#At every node: (1) push to q, (2)
#For every count: pop and print from queue
#Count should finish at a level, before going deeper
#When to print? Once all nodes at a level are done
#Print iteratively
def levelTraversal(treenode:Node) -> List[Node]:
    print(f"Printing by level order traversal:")
    #Create a queue
    que = []
    printque=[]
    #Append to queue
    que.append(treenode)
    printque.append(treenode.val)
    print(f"printque:{printque}")
    index = 0
    size1 = 1
    while(size1>0):
        count=0
        temp=[]
        tempprint=[]
        print(f"Start:index={index},size1={size1},printque[{index}]:{printque[index]}")
        #Print the full queue
        for count in range(0,size1):
            print(f"count={count},size1={size1}")
            tempnode = que.pop()
            print(f"tempnode:{tempnode},tempnode.left:{tempnode.left},tempnode.right:{tempnode.right}")
            if(tempnode.left is not None):
                print(f"tempnode.left:{tempnode.left.val}")
                temp.append(tempnode.left)
                val = tempnode.left.val if tempnode.left !=None else 0
                tempprint.append(val)
            if(tempnode.right is not None):
                print(f"tempnode.right:{tempnode.right.val}")
                temp.append(tempnode.right)
                val = tempnode.right.val if tempnode.right !=None else 0
                tempprint.append(val)
            print(f"temp:{temp}")
            print(f"tempprint:{tempprint}")
        que.append(temp)
        printque.append(list(tempprint))
        index = index+1
        print(f"End:index={index},size1={size1},printque[{index}]:{printque[index]}")
        print(f"que:{que}")
        print(f"len(que[index]):{len(que[0])}")
        size1 = 1 if index==0 else len(que[0])
        print(f"End:Que:{que}")
    return printque


#Create root
root = Node(5)
#Create left
root.left = Node(4)
root.right = Node(8)
#Create third row
root.left.left = Node(11)
root.right.left = Node(13)
root.right.right = Node(4)
#Create fourth row
root.left.left.left = Node(7)
root.left.left.right = Node(2)
root.right.right.right = Node(1)

#Print the tree
que = levelTraversal(root)
print(f"Printing tree",que)
