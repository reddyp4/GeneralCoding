/*

925. Long Pressed Name
Solved
Easy
Topics
Companies
Your friend is typing his name into a keyboard. Sometimes, when typing a character c, the key might get long pressed, and the character will be typed 1 or more times.

You examine the typed characters of the keyboard. Return True if it is possible that it was your friends name, with some characters (possibly none) being long pressed.

 

Example 1:

Input: name = "alex", typed = "aaleex"
Output: true
Explanation: 'a' and 'e' in 'alex' were long pressed.
Example 2:

Input: name = "saeed", typed = "ssaaedd"
Output: false
Explanation: 'e' must have been pressed twice, but it was not in the typed output.
 

Constraints:

1 <= name.length, typed.length <= 1000
name and typed consist of only lowercase English letters.

*/

class Solution {
    public:
        bool isLongPressedName(string name, string typed) {
            //two pointer approach
            int p1=0,p2=0,k=0;
            int len1=name.length(),len2=typed.length();
            while(p1<len1 && p2<len2)
            {
                if(name[p1]!=typed[p2])  return false;
                while(p1<len1 && p2<len2 && name[p1]==typed[p2])
                {
                    p2++,p1++;
                }
                if(name[p1]==name[p1-1])    return false;
                while(typed[p2]==typed[p2-1]) p2++;
                //cout<<"p1:"<<p1<<",p2:"<<p2<<endl;
            }
            if(p1==len1 && p2==len2)    return true;
            return false;
        }
    };

/* 
Runtime 0ms
Beats 100.00%

Memory 8.76MB
Beats 46.33%

*/