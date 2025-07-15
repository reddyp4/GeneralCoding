/*
3. Longest Substring Without Repeating Characters
Solved
Medium
Topics
Companies
Hint

Given a string s, find the length of the longest

without duplicate characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

 

Constraints:

    0 <= s.length <= 5 * 104
    s consists of English letters, digits, symbols and spaces.

*/

//Method1, at every index, 
//      start a hash map of characters with count of 1
//          once encountered repeating, drop begin, repeat

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s=="")   return 0;
        int len1=s.size(),left=0,right=0,maxLength=0,currentLength=0;
        if(len1==1) return 1;
        //Initiate map
        vector<int> myMap(127,0);     //index=ascii of char-a, value=count
        //set the right
        right=left+1;
        //cout<<"ASCII:"<<int(' ')<<endl;
        myMap[s[left]-int(' ')]=1;
        while(left<len1 && right<len1)
        {
            //move until repeat & update map
            while(right<len1 && (myMap[s[right]-int(' ')]==0) )
            {
                myMap[s[right]-int(' ')]=right;
                right++;
            }
            //cout<<"string:left:"<<s[left]<<",right:"<<s[right-1]<<endl;
            //update max length
            maxLength = (maxLength>(right-left))?maxLength:(right-left);
            //move left by 1, update map for left before moving
            myMap[s[left]-int(' ')]=0;
            left++;
        }
        return maxLength;
    }
};

/*
Runtime 3ms Beats84.74%
Analyze Complexity
Memory 11.12MB Beats91.39%
*/