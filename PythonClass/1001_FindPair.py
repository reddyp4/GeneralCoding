#Problem
#Given an array of integers arr and an integet k, create a boolean function that checks
#  if there exist two elements in arr such that we get k when we add them together
# Example-1
# Input: arr = [4,5,1,-3,6], k=11
# Output: true 
# Explanation: 5+6 is equal to 11 

#Steps: 1) Sort, 2) Find pair

##########################################
# USER INPUT ARRAY
import math

def findPair(arr,k):
    #Sort
    arr.sort()
    print(f"Sorted array:{arr}")

    #Find pair
    i=0
    j=len(arr)-1
    while(i!=j):
        #check sum
        if(arr[i]+arr[j]==k):
            print(f"sum found: i={i},j={j}")
            break
        # move j
        elif(arr[i]+arr[j]>k):
            j=j-1
            print(f"move i: i={i},j={j}")
        #move i
        elif(arr[i]+arr[j]<k):
            i=i+1
            print(f"move j: i={i},j={j}")

    if(i==j):
        return False
    else:
        return True


arr = input("Input: arr = ").split(",")
print(arr)
sum1 = input("Number: num1 = ")
sum1=int(sum1)
for k in range(0,len(arr)):
    arr[k] = int(arr[k])
print(arr)
print(sum1)

if(findPair(arr,sum1)):
    print(f"Yes sum!!!")
else:
    print(f"No sum!!!")

