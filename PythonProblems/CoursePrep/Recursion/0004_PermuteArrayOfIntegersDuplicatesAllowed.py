'''
Permute Array Of Integers Duplicates Allowed
Given an array of numbers with possible duplicates, return all of its permutations in any order.

Example
{
"arr": [1, 2, 2]
}
Output:

[
[1, 2, 2],
[2, 1, 2],
[2, 2, 1]
]
Notes
Constraints:

1 <= size of the input array <= 9
0 <= any array element <= 9
'''
seen = {}

def permute(full,current,final,key):
    if(len(full)==0):
        #print("final:",final,"current:",current)
        if(key not in seen):
            final.append(current[:])
            seen[key]=1
        return
    lenkey = len(key)
    for index,elem in enumerate(full):
        key=key+str(elem)
        current.append(elem)
        fullcopy=full[:index]
        #print("current1:",current)
        fullcopy.extend(full[index+1:])
        permute(fullcopy,current,final,key)
        key=key[:lenkey]
        current.pop()
        #print("current2:",current)
    return

def get_permutations(arr):
    """
    Args:
     arr(list_int32)
    Returns:
     list_list_int32
    """
    # Write your code here.
    result = []
    permute(arr,[],result,"")
    return result
