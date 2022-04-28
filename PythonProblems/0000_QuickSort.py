#Quick Sort Algorithm

#Structure: QuickSort algo->Partition->Recursion
def swap(i,j):
    c=i
    i=j
    i=c

#Partition-arrange lower to left, higher to right
def Partition(arr,low,high):
    pivot = arr[low]
    i=low
    j=high
    while(i<j):
        while(arr[i]<pivot):
            i+=1;
        while(arr[j]>pivot):
            j-=1;
        if(i<j):
            swap(arr[i],arr[j])
    swap(arr[low],arr[j])
    return j

#Actual Quicksort
def quickSort(start,end):
    pivot=(int)(end-start)/2
    low=start
    high=end
    while(low<high):
        j=Partition(arr,low,high)
        quickSort(low,j)
        quickSort(j+1,high)

arr = [10,80,30,90,40,50,70]
len1 = len(arr)
quickSort(0,len1-1)
