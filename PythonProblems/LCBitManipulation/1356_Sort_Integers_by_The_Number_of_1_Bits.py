''''
You are given an integer array arr. Sort the integers in the array in ascending order by the number of 1's in their binary representation and in case of two or more integers have the same number of 1's you have to sort them in ascending order.

Return the array after sorting it.
Example 1:

Input: arr = [0,1,2,3,4,5,6,7,8]
Output: [0,1,2,4,8,3,5,6,7]
Explantion: [0] is the only integer with 0 bits.
[1,2,4,8] all have 1 bit.
[3,5,6] have 2 bits.
[7] has 3 bits.
The sorted array by bits is [0,1,2,4,8,3,5,6,7]
Example 2:

Input: arr = [1024,512,256,128,64,32,16,8,4,2,1]
Output: [1,2,4,8,16,32,64,128,256,512,1024]
Explantion: All integers have 1 bit in the binary representation, you should just sort them in ascending order.

// Sorting is easier in Python
'''

#Step1: Write BitCount function and assign the #bits
#Step2: Write Sorting algorithm - do all sorting algorithms seperately in Python

'''
class Solution:
    def getBits(arr):
        lenth1 = len(arr)
        for i in range[0,lenth1]:
            val=0
            nums = arr[i]
            while(arr>0):
                val+=1
                nums = (nums^(nums-1))
            bits[i] = val
        return bits
    #def sortByBits(self, arr: List[int]) -> List[int]:
    #    lenth1 = len(arr)
        #Get bits into array
        #Sort array based on bits

#array = [0,1,2,3,4,5,6,7,8]
array = [0,8]
BITS = Solution.getBits(array)

print(BITS)
'''

class Solution:
    def sortByBits(self, arr: List[int]) -> List[int]:
        #Get bits in each number and store to List of Lists
        #Sort List by first element and then second element
        bits = list()
        for index,ele in enumerate(arr):
            nobits=0
            num=ele
            while(num is not 0):
                num=num&(num-1)
                nobits=nobits+1
            bits.append(nobits)
        #now make list of lists
        final=zip(bits,arr)
        #sort final
        finalS=sorted(final,key=lambda x:(x[0],x[1]))
        result = [item[1] for item in finalS]
        return result