'''
17. Letter Combinations of a Phone Number
Solved
Medium
Topics
Companies
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.


 

Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Example 2:

Input: digits = ""
Output: []
Example 3:

Input: digits = "2"
Output: ["a","b","c"]
 

Constraints:

0 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9'].
'''

class Solution:
    phone = ["","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz",""]
    def makeString(self,s,index,digits,final):
        if(len(s)==len(digits)):
            final.append(s[:])
            return
        for c in self.phone[int(digits[index])-1]:
            self.makeString(s+c,index+1,digits,final)

    def letterCombinations(self, digits: str) -> List[str]:
        final=[]
        if(digits==""):
            return []
        self.makeString("",0,digits,final)
        return final

'''
Recursive with existing list
'''