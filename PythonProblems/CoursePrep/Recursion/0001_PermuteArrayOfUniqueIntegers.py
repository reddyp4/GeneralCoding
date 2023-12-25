'''
Permute Array Of Unique Integers
Given an array of unique numbers, return in any order all its permutations.

Example
{
"arr": [1, 2, 3]
}
Output:

[
[1, 2, 3],
[1, 3, 2],
[2, 1, 3],
[2, 3, 1],
[3, 2, 1],
[3, 1, 2]
]
Notes
Constraints:

1 <= size of the input array <= 9
0 <= any array element <= 99
'''
def recur(original,current,len1,final):
    if(len(current)==len1):
        newlist=current.copy()
        final.append(newlist)
        #print("final:",final)
        return
    #print("Original1:",original,"Current1:",current)
    for index in range(len(original)):
        elem = original[index]
        current.append(elem)
        #print("Original2:",original[:index]+original[index+1:],"Current2:",current)
        recur(original[:index]+original[index+1:],current,len1,final)
        #print("Original3:",original[:index]+original[index+1:],"Current3:",current)
        current.pop()
    return

def get_permutations(arr):
    """
    Args:
     arr(list_int32)
    Returns:
     list_list_int32
    """
    # Write your code here.
    final=[]
    recur(arr,[],len(arr),final)
    return final