'''
345. Reverse Vowels of a String
Easy
3.3K
2.4K
company
Apple
company
Bloomberg
company
Yahoo
Given a string s, reverse only all the vowels in the string and return it.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.

 

Example 1:

Input: s = "hello"
Output: "holle"
Example 2:

Input: s = "leetcode"
Output: "leotcede"
 

Constraints:

1 <= s.length <= 3 * 105
s consist of printable ASCII characters.
'''

class Solution:
    def reverseVowels(self, s: str) -> str:
        len1=len(s)
        if(len1==1):
            return s
        vowels = {"a","e","i","o","u","A","E","I","O","U"}
        # M1: Two pointer approach
        '''
        left=0
        right=len1-1
        leftans, rightans=str(), str()
        while(left<=right):
            while((left<=right) and (s[left] not in vowels)):
                leftans=leftans+s[left]
                left=left+1
            while((left<=right) and (s[right] not in vowels)):
                rightans=s[right]+rightans
                right=right-1
            #swap since we reached vowel positions
            if(left<right):
                leftans=leftans+s[right]
                rightans=s[left]+rightans
            if(left==right):
                leftans=leftans+s[right]
            right=right-1
            left=left+1
        ans=leftans+rightans
        return ans
        '''
        #M2: Put all vowels in array, pick vowels from end
        '''
        vowellist={}
        ans=str()
        for i in range(0,len1):
            if(s[i] in vowels):
                vowellist.append(s[i])
        lenw=len(vowellist)
        k=0
        #now run through s again
        for i in range(0,len1):
            if(s[i] in vowels):
                ans=ans+str(vowellist[lenw-1-k])
                k=k+1
            else:
                ans=ans+s[i]
        return ans
        '''
        #M3: M2, with list
        '''
        vowellist=[]
        ans=[]
        slist=list(s)
        for i in range(0,len1):
            if(slist[i] in vowels):
                vowellist.append(slist[i])
        lenw=len(vowellist)
        k=0
        #now run through s again
        for i in range(0,len1):
            if(slist[i] in vowels):
                ans.append(vowellist[lenw-1-k])
                k=k+1
            else:
                ans.append(slist[i])
        return "".join(ans)
        '''
        #M4: Two pointer approach, with same s converted to list
        s = list(s)
        vowels = set(list("aeiouAEIOU"))
        
        l, r = 0, len(s) - 1
        while l < r:
            if s[l] in vowels and s[r] in vowels:
                s[l], s[r] = s[r], s[l]
                l += 1
                r -= 1
                
            if s[l] not in vowels:
                l += 1
            if s[r] not in vowels:
                r -= 1
                
        return "".join(s)