#Quick Sort Algorithm

#Structure: QuickSort algo->Partition->Recursion
def swap(arr,i,j):
    print(f"Swap: i={i},j={j}")
    c=arr[i]
    arr[i]=arr[j]
    arr[j]=c

#Partition-arrange lower to left, higher to right
def Partition(arr,low,high):
    print(f"Entering Partition: arr={arr}")
    pivot = len(arr)-1
    i=low
    j=high
    if(i<j):
        if(arr[i]<arr[pivot]):
            i+=1
        if(arr[j]>arr[pivot]):
            j-=1
        if(arr[i]>arr[j]):
            swap(arr,i,j)
    swap(arr,pivot,j)
    return j

#Actual Quicksort
def quickSort(arr,start,end):
    print("Entering QuickSort:arr={arr}")
    pivot=len(arr)-1
    low=start
    high=end
    print(f"QuickSort: pivot={pivot},low={low},high={high}")
    if(low<high):
        j=Partition(arr,low,high)
        #print(f"Finished Partition,arr={arr}")
        quickSort(arr,low,j-1)
        quickSort(arr,j+1,high)

arr = [10,80,30,90,40,50,70]
len1 = len(arr)
#running pivot as last element
quickSort(arr,0,len1-2)

