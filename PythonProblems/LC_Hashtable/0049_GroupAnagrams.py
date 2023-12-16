'''
49. Group Anagrams
Medium
17.8K
531
company
Amazon
company
Yandex
company
Apple
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Example 2:

Input: strs = [""]
Output: [[""]]
Example 3:

Input: strs = ["a"]
Output: [["a"]]
 

Constraints:

1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] consists of lowercase English letters.
'''

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        #M1: For each string form the hashtable, and append, if hashtables match
        #M2: Sort each string, compare and append
        if(len(strs)==1):
            return [strs]
        sortedstrs = []
        #Create sorted list set (unique strings only)
        for s in strs:
            sorteds = ''.join(sorted(s))
            if(sorteds not in sortedstrs):
                sortedstrs.append(sorteds)
        final = [[] for i in range(len(sortedstrs))]
        #Now add each string
        for s in strs:
            sorteds = ''.join(sorted(s))
            index = sortedstrs.index(sorteds)
            final[index].append(s)
        return final