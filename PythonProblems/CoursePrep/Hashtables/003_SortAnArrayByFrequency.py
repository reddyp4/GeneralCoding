'''
Sort An Array By Frequency
Given a list of numbers, sort it in increasing order based on the frequency of the elements in the list.

Example One
{
"nums": [2, 4, 1, 4, 4, 1]
}
Output:

[2, 1, 1, 4, 4, 4]
Example Two
{
"nums": [10, 20, 15, 20]
}
Output:

[15, 10, 20, 20]
Notes
If multiple elements have the same frequency, sort them in decreasing order.
Constraints:

1 <= size of the input list <= 105
-105 <= any element of the input list <= 105
'''


def sort_array_by_frequency(nums):
    """
    Args:
     nums(list_int32)
    Returns:
     list_int32
    """
    # Write your code here.
    d={}
    for index,elem in enumerate(nums):
        if elem in d:
            d[elem]=d[elem]+1
        else:
            d[elem]=1
    sortedd = dict(sorted(d.items(),key=lambda x:(x[1],-x[0]) ) )
    result=[]
    for key in sortedd:
        newlist = [key]*sortedd[key]
        result=result+newlist
    return result

'''
Time limit exceeding for using result=result+newlist
Instead do result.extend(newlist)

'''