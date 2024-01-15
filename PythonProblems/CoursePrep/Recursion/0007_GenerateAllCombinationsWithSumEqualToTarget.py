'''
Generate All Combinations With Sum Equal To Target

Given an integer array, generate all the unique combinations of the array numbers that sum up to a given target value.

Example One
{
"arr": [1, 2, 3],
"target": 3
}
Output:

[
[3],
[1, 2]
]
Example Two
{
"arr": [1, 1, 1, 1],
"target": 2
}
Output:

[
[1, 1]
]
Notes
Each number in the array can be used exactly once.
All the returned combinations must be different. Two combinations are considered different if their sorted version is different.
The order of combinations and the order of the numbers inside a combination does not matter.
Constraints:

1 <= size of the input array <= 25
1 <= value in the array <= 100
1 <= target value <= 2500
'''
seen = {}

def recursive(current,key,index,target,final,arr):
    #print("current:",current,"key:",key,"index:",index,"final:",final)
    if(len(current)!=0 and sum(current)>target):
        print("End1")
        return
    if(len(current)!=0 and sum(current)==target):
        print("current3:",current,"key:",key,"index:",index,"final:",final)
        if(key not in seen):
            newcurrent=current.copy()
            final.append(newcurrent)
            seen[key]=1
        return
    if(index==len(arr)):
        return
    if(arr[index]>target):
        #print("End2")
        return
    oldkey=key
    current.append(arr[index])
    #print("current2:",current,"key:",key,"index:",index,"final:",final)
    recursive(current,key+str(arr[index]),index+1,target,final,arr)
    current.pop()
    recursive(current,oldkey,index+1,target,final,arr)
    #print("current1:",current,"key:",key,"index:",index,"final:",final)

def generate_all_combinations(arr, target):
    """
    Args:
     arr(list_int32)
     target(int32)
    Returns:
     list_list_int32
    """
    # Write your code here.
    final=[]
    arr.sort()
    print("arr:",arr)
    recursive([],"",0,target,final,arr)
    #print("final:",final)
    return final

'''
Improvement by sorting
'''