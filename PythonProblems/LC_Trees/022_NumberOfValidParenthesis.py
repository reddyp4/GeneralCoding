'''
22. Generate Parentheses
Medium
17.7K
712
company
Adobe
company
Apple
company
Amazon
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]
 

Constraints:

1 <= n <= 8
'''
class Solution:
    # makeString function to create string for each n
    def makeStr(self,output: List[str], n:int, s: str, left:int, right: int):
        #illegal string, left<right or left>n or right>n
        if(left<right) or (left>n) or (right>n):
            return
        #good string balanced string, left=right, and not in list
        if((left==right==n) and s not in output):
            output.append(s)
        #left child, only if left<n, left>=right
        if(left<n):
            self.makeStr(output, n, s+"(", left+1, right)
        #right child, only if right<n, and left>right
        if((right<n) and (left>right)):
            self.makeStr(output, n, s+")", left, right+1)

    def generateParenthesis(self, n: int) -> List[str]:
        #M1: BST with backtracking. Beats:T(5%),S(7%)
        output=[]
        self.makeStr(output,n,"",0,0)
        return output