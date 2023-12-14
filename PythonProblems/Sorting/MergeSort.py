'''
Implementation of merge sort
'''

def merge_sort(arr):
    """
    Args:
     arr(list_int32)
    Returns:
     list_int32
    """
    # Write your code here.
    print("arr:",arr)
    if(len(arr)<=1):
        return arr
    #Get midpoint
    mid = int(len(arr)/2)
    #Recursive sort left, sort right
    leftarr = merge_sort(arr[:mid])
    rightarr = merge_sort(arr[mid:])
    print("Sorted letf:",leftarr)
    print("Sorted right:",rightarr)
    #combine
    i,j,k = 0,0,0
    while(i<len(leftarr) and j<len(rightarr)):
        if(leftarr[i]<rightarr[j]):
            arr[k]=leftarr[i]
            i=i+1
        elif(leftarr[i]>rightarr[j]):
            arr[k]=rightarr[j]
            j=j+1
        elif(leftarr[i]==rightarr[j]):
            arr[k]=leftarr[i]
            k=k+1
            arr[k]=rightarr[j]
            i,j = i+1, j+1
        k = k+1
    while(i<len(leftarr)):
        arr[k]=leftarr[i]
        i=i+1
        k=k+1
    while(j<len(rightarr)):
        arr[k]=rightarr[j]
        j=j+1
        k=k+1
    print("Sorted array:",arr)
    return arr

#arr = [5, 8, 3, 9, 4, 1, 7]
#arr = [-1,-2,-3,-4,-5,-6]
#arr = [-1,-5,-4,-3,-2,-10]
arr = [-1,-2,-3,-4]
#print("Initial:",arr)
sortarr = merge_sort(arr)
print("Sorted arr:",sortarr)
