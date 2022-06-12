#Quick Sort Algorithm

#Structure: QuickSort algo->Partition->Recursion
def swap(arr,i,j):
    #print(f"Swap: i={i},j={j}")
    c=arr[i]
    arr[i]=arr[j]
    arr[j]=c

#Partition-arrange lower to left, higher to right
def Partition(arr,low,high):
    print(f"Entering Partition: arr={arr}")
    pivot = high
    i=low
    j=high-1
    while(i<j):
        if(arr[i]<arr[pivot]):
            i+=1
        if(arr[j]>arr[pivot]):
            j-=1
        if(arr[i]>arr[j]):
            swap(arr,i,j)
            print(f"Swapped: arr={arr},i={i},j={j},pivot={pivot}")
            i+=1
            j-=1
    j+=1
    swap(arr,pivot,j)
    return j

#Actual Quicksort
def quickSort(arr,start,end,count):
    count+=1
    if(count<10):
        print(f"Entering QuickSort:arr={arr},count={count},low={start},high={end}")
        if(start<end):
            j=Partition(arr,start,end)
            print(f"Finished Partition,arr={arr},j={j}")
            quickSort(arr,start,j-1,count)
            quickSort(arr,j+1,end,count)

count=0
arr = [10,80,30,90,40,50,70]
len1 = len(arr)
#running pivot as last element
quickSort(arr,0,len1-1,count)
#Final Array
print(f"Final arrary={arr}")
