#Write a function rotate(ar[], d, n) that rotates arr[] of size n by d elements
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

array1 = [1,2,3,4,5,6,7,8]
print(array1)
array1 = rotate(array1,2,8)
print(array1)
