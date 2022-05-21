#Write a function rotate(ar[], d, n) that rotates arr[] of size n by d elements
from distutils.ccompiler import new_compiler
from itertools import count
from re import L

def rotate(L, d, n):
    newL=[]
    #create a new array
    for count,elem in enumerate(L):
        if((count+d)<n):
            newL.append(L[count+d])
        else:
            newL.append(L[count-(n-d)])
    return newL


#Given an array (or string), the task is to reverse the array/string.
def reverse1(L):
    newL=[]
    len1=len(L)
    for count,ele in enumerate(L):
        newL.append(L[len1-1-count])
    return newL
def reverse2(L):
    len1=len(L)
    for i in range(0,(int)(len1/2)-1):
        c=L[i]
        L[i] = L[len1-1-i]
        L[len1-1-i] = c
    return L

#Rearrange array such that arr[i] >= arr[j] if i is even and arr[i]<=arr[j] if i is odd and j < i
#Given an array of n elements. 
# Our task is to write a program to rearrange the array such that
#  elements at even positions are greater than all elements before it and
#  elements at odd positions are less than all elements before it.
def rearrange(L):
    return L

array1 = [1,2,3,4,5,6,7,8]
print(array1)
#array3 = rotate(array1,2,8)
#print(array3)
#array2 = reverse1(array1)
#print(array2)
#array4 = reverse2(array1)
#print(array4)
array5 = rearrange(array1)
print(f"Rearranged:{array5}")
