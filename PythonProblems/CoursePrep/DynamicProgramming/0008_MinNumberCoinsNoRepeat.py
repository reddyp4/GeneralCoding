# Libraries Included:
# Numpy, Scipy, Scikit, Pandas


# [2,2,2,4,6] target = 10
# output 2 becuase 10 = 4+6 using two numbers from the list
# [2,2,2,4,6] target = 13
# output = -1
# output = least amount of numbers from the list that sum up to the target

#input may not be sorted
#input can have duplicates
#may be target cannot in reached

'''
[2 2 2 4 6] 
newtarget = target-[index] start with array[1:]
newtarget = target-skip[index] start with array[1:]

sort
2 4 6 8 10... 
[1] [2,1]=[1]
[0]=(0,0)
(0,1)=(0,0)+[1]
(0,2)=(0,1)+[2]
(0,n-1)

(1)
(1,2).. (1,n-1)

Approach: Make a sumarray (dict in python), where each key is sum, and value is number of elements being added
What we need:
(target, ?)
What we already have:
(target-1, x)
(target-2, y)
...
(4, 1)
(3, -1)
(2, 1)
(1, -1)


[2 2 2 4 6]
{2:1, 4:1, 6:1}
{3:0}
{4: 4-2:1, 4-2:1 4-2=2:1 +1 
'''

def minCount(array,target):
    count=0
    array.sort()
    if(target<array[0]):
        #cannot make any sum
        return -1
    if(sum(array)<target):
        #cannot reach target
        return -1
    d={}
    len1=len(array)
    for i in range(len1):
        #single count values
        d[array[i]]=1
        #instead of count, make a list of elements here [i]
    print("d:",d)
    for newtarget in range(array[0]+1,target+1):
        minVal=10**10
        #iterate through each element in the array and if present, add count+1
        for j in range(len1):
            #now to check if element has already been counted
            diff = newtarget-array[j]
            if((newtarget-array[j]) in d) and d[newtarget-array[j]]!=0 and (diff in array and not in d[key]):
                #update the count for each index
                count=d[newtarget-array[j]]+1
                #update minVal at the same time
                minVal=minVal if (minVal<count) else count
        #update count for newtarget
        if(newtarget in d):
            d[newtarget]=minVal if (minVal<d[newtarget]) else d[newtarget]
        else:
            d[newtarget]=minVal if (minVal!=10**10) else 0
    print("d:",d)
    return d[target]

array = [2,2,2,4,6]
target = 16
print("Min numbers needed:",minCount(array,target))



