'''
N Choose K Combinations
Given two integers n and k, find all the possible unique combinations of k numbers in range 1 to n.

Example One
{
"n": 5,
"k": 2
}
Output:

[
[1, 2],
[1, 3],
[1, 4],
[1, 5],
[2, 3],
[2, 4],
[2, 5],
[3, 4],
[3, 5],
[4, 5]
]
Example Two
{
"n": 6,
"k": 6
}
Output:

[
[1, 2, 3, 4, 5, 6]
]
Notes
The answer can be returned in any order.

Constraints:

1 <= n <= 20
1 <= k <= n
'''


def recur(full,current,final,k):
    if(len(current)==k):
        #print("final2:",final,"current2:",current)
        final.append(current[:])
        return
    for index,elem in enumerate(full):
        current.append(elem)
        newfull=[]
        newfull.extend(full[index+1:])
        #print("final:",final,"newfull1:",newfull,"current1:",current)
        recur(newfull,current,final,k)
        current.pop()
        #print("final3:",final,"newfull:",newfull,"current:",current)
    return 
        

def find_combinations(n, k):
    """
    Args:
     n(int32)
     k(int32)
    Returns:
     list_list_int32
    """
    # Write your code here.
    final=[]
    full = range(1,n+1)
    recur(full,[],final,k)
    return final

'''
Notes:
In python3, lists are passed by reference, to remember to pop after return from recursion
Additionally, while appending a list to a list of lists, use .append(list[:]) for copy
'''