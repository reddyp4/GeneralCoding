'''
# Tower of Hanoi
https://en.wikipedia.org/wiki/Tower_of_Hanoi
Only smaller disk can be put on top of larger disk

Input: 3 (# of disks)
Output: (ways to move from stick A, though B, to C)
Disk 1 moved from A to C
Disk 2 moved from A to B
Disk 1 moved from C to B
Disk 3 moved from A to C
Disk 1 moved from B to A
Disk 2 moved from B to C
Disk 1 moved from A to C

1 disk = [1][][]-[][1][]=f(1)=1
2 disks = [1,2][][]-[2][1][]-[][1][2]-[][][1,2]=3
          f(1)              +f(1)
n disks, (n-1) disks and 
f(n) = f(n-1)+

1, moves
1,2 disks 1 has to move, 2 has to move, 1 moves to 2
f(3) = f(2)+f(2)+f(1)
three lists, [1,2,3][][]      
             [2,3][1][]    
             [3][1][2]      f(2)  
             [3][][1,2]    
             
             [][3][1,2]    f(1)
             
             [1][3][2]    
             [1][2,3][]    f(2)
             [][1,2,3][]    

f(n,A,B,C)=f(1-(n-1),A,C,B)+f(n,A,C)+f(1-(n-1),B,C,A)
f(1,A,C,B) 1st disk should be moved from A though C to B
+
f(2~n, A,B,C) 2 to n disks should be moved from A with the help of B to C <-- resursion
+
f(1,B,A,C)

1)      add elements from left, left is like top, also pop from left
        continue until we cannot operation on this state-1
2)    choose a different state between 2&3
3)    pick the smallest, and move except state-1
4)    

'''
class Solution:
    def __init__(self,n):
        Hanoi=[list(range(1,n+1)),[],[]]
        print(Hanoi)
    
    def printState(self):
        print(self.Hanoi)
        
    def recursion(self,n,start):
        if(n==1):
            #move from start to other state
            val=self.Hanoi[start].pop(0)
            self.Hanoi[1].append(val)
            return
        #n-1
        self.recursion(n-1)
        #move n
        #n-1
        self.recursion(n-1)
     
    def hanoi():
        self.recursion(n,1)

n=1
sol=Solution(n)
sol.printState()
#sol.hanoi()
#sol.printState()

