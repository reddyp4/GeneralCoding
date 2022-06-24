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
    #Create a queue, this is cleared every level
    que = []
    #printque, is the final queue to be returned
    printque=[]
    #now for every level, push into queue
    que.append(treenode)
    printque.append(treenode.val)
    #run loop until end of queue
    size1 = len(que)
    while(size1>0):
        #initialize queue2
        que2 = []
        printque2 = []
        print(f"Start:size1:{size1},{que}")
        #Now run count on queue1 size
        for index in range(0,size1):
            # pop each element
            tempnode = que.pop()
            print(f"tempnode:{hex(id(tempnode))}")
            #check if tempnode is None, and left is None
            if((tempnode is not None) & (tempnode.left is not None)):
                print(f"tempnode.left.val={tempnode.left.val}")
                que2.append(tempnode.left)
                printque2.append(tempnode.left.val)
            #if not push to queue2
            #do same with right
            if((tempnode is not None) & (tempnode.right is not None)):
                print(f"tempnode.right.val={tempnode.right.val}")
                que2.append(tempnode.right)
                printque2.append(tempnode.right.val)
        #append que2 to que
        print(f"que2:{que2}")
        #que.append(que2)
        que.extend(que2)
        print(f"que:{que}")
        printque.append(list(printque2))
        print(f"End:printque:{printque}")
        #update size1
        size1 = len(que)
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
#Print address & values
print(f"root:{hex(id(root))},val:{root.val},left:{hex(id(root.left))},right:{hex(id(root.right))}")
print(f"level1:{hex(id(root.left))},val:{root.left.val},left:{hex(id(root.left.left))},right:{hex(id(root.left.right))}")
print(f"level2:{hex(id(root.right))},val:{root.right.val},left:{hex(id(root.right.left))},right:{hex(id(root.right.right))}")
print(f"level3:{hex(id(root.left.left))},val:{root.left.left.val},left:{hex(id(root.left.left.left))},right:{hex(id(root.left.left.right))}")
#print(f"level3:{root.left.right},val:{root.left.right.val},left:{root.left.right.left},right:{root.left.right.right}")
print(f"level3:{hex(id(root.right.left))},val:{root.right.left.val},left:{hex(id(root.right.left.left))},right:{hex(id(root.right.left.right))}")
print(f"level3:{hex(id(root.right.right))},val:{root.right.right.val},left:{hex(id(root.right.right.left))},right:{hex(id(root.right.right.right))}")

#Print the tree
que = levelTraversal(root)
print(f"Printing tree",que)

