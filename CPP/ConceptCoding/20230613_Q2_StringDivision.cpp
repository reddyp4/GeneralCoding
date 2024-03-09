/*
Find whether string s is divisible by string t. A string s divisible by string t if string t can be concatenated some number of times to obtain the string s.



﻿If s is divisible, find the smallest string u such that it can be concatenated some number of times to obtain both s and t.

If it is not divisible, set the return value to -1.

Finally, return the length of the string u or -1.



Example 1:

s = "bcdbcdbcdbcd"

t = "bcdbcd"

If string t is concatenated twice, the result is "bcdbcdbcdbcd" which is equal to the string s. The string s is divisible by string t.

Since it passes the first test, look for the smallest string u that can be concatenated to create both strings s and t.

The string "bcd" is the smallest string that can be concatenated to create both strings s and t.

The length of the string u is 3, the integer value to return.


Example 2:

s = "bcdbcdbcd"

t = "bcdbcd"

If string t is concatenated twice, the result is "bcdbcdbcdbcd" which is greater than string s. There is an extra "bcd" in the concatenated string.

The string s is not divisible by string t, so return -1.

Idea: Get str1.length(), str2.length(). Divide bigger/smaller = n = integer. 
Now take smaller string, and do new stringstring..string n times. compare to bigger string
*/
