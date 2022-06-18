''''
Palindromic Decomposition Of A String

Find all palindromic decompositions of a given string s.

A palindromic decomposition of string is a decomposition of the string into substrings, such that all those substrings are valid palindromes.

Example
{
"s": "abracadabra"
}
Output:

["a|b|r|a|c|ada|b|r|a", "a|b|r|aca|d|a|b|r|a", "a|b|r|a|c|a|d|a|b|r|a"]
Notes
Any string is its own substring.
Output should include ALL possible palindromic decompositions of the given string.
Order of decompositions in the output does not matter.
To separate substrings in the decomposed string, use | as a separator.
Order of characters in a decomposition must remain the same as in the given string. For example, for s = "ab", return ["a|b"] and not ["b|a"].
Strings in the output must not contain whitespace. For example, ["a |b"] or ["a| b"] is incorrect.
Constraints:

1 <= length of s <= 20
s only contains lowercase English letters.
'''


def generate_palindromic_decompositions(s):
    """
    Args:
     s(str)
    Returns:
     list_str
    """
    # Write your code here.
    return []
