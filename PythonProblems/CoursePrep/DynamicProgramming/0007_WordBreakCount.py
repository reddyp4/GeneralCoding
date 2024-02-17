'''
Word Break Count
Given a dictionary of words and a string txt, find the number of ways the string can be broken down into the dictionary words. Return the answer modulo 109 + 7.

Example
{
"dictionary": ["kick", "start", "kickstart", "is", "awe", "some", "awesome"],
"txt": "kickstartisawesome"
}
Output:

4
Here are all four ways to break down the string into the dictionary words:

kick start is awe some
kick start is awesome
kickstart is awe some
kickstart is awesome
4 % 1000000007 = 4 so the correct output is 4.

Notes
Constraints:

1 <= number of words in the dictionary <= 2 * 105
1 <= length of any dictionary word <= 102
1 <= length of the string txt <= 2 * 103
Dictionary words and the string txt all consist of lowercase latin characters only (no whitespace, in particular).
'''


def word_break_count(dictionary, txt):
    """
    Args:
     dictionary(list_str)
     txt(str)
    Returns:
     int32
    """
    # Write your code here.
    return 0
