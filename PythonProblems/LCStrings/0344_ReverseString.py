'''
344. Reverse String
Easy
7.2K
1.1K
company
Apple
company
Amazon
company
Adobe
Write a function that reverses a string. The input string is given as an array of characters s.

You must do this by modifying the input array in-place with O(1) extra memory.

 

Example 1:

Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
Example 2:

Input: s = ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]
 

Constraints:

1 <= s.length <= 105
s[i] is a printable ascii character.
'''
class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        #Method-1: Swap
        len1=len(s)
        #swap
        '''
        for i in range(int(len1/2)):
            a=s[i]
            s[i]=s[len1-1-i]
            s[len1-1-i]=a
        '''
        #One line swap
        s[:] = s[::-1]