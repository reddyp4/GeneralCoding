'''
Find All Well-formed Brackets
Given a positive integer n, return ALL strings of length 2 * n with well-formed round brackets.

Example
{
"n": 3
}
Output:

[
"((()))",
"(()())",
"(())()",
"()(())",
"()()()"
]
Any array containing these five strings in any order is a correct output.

Notes
Order of strings in the returned array is insignificant, e.g. for n = 2 both ["(())", "()()"] and ["()()", "(())"] will be accepted.
Constraints:

1 <= n <= 12
Only use round brackets. '(' and ')'
'''
#Method: Initial List of strings, (,)
#Well-formed brackets, every ( is followed by )
#Final string length = 2n
#Worker at index, can pick ( or )
#One way is to make all possible strings and verify later
#Better way, start with initial List containing n (, n )
#Start making combinations, since order is important
#Every worker has two choices, ( or ) that is popped from initial list
#to be continue in VSCode ide


def find_all_well_formed_brackets(n):
    """
    Args:
     n(int32)
    Returns:
     list_str
    """
    # Write your code here.
    return []
