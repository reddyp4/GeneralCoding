''''
Segregate Even And Odd Numbers
Given an array of numbers, rearrange them in-place so that even numbers appear before odd ones.

Example
{
"numbers": [1, 2, 3, 4]
}
Output:

[4, 2, 3, 1]
The order within the group of even numbers does not matter; same with odd numbers. So the following are also correct outputs: [4, 2, 1, 3], [2, 4, 1, 3], [2, 4, 3, 1].
Notes
It is important to practice solving this problem by rearranging numbers in-place.
There is no need to preserve the original order within the even and within the odd numbers.
We look for a solution of the linear time complexity that uses constant auxiliary space.
Constraints:

1 <= length of the array <= 105
1 <= element of the array <= 109
'''
def segregate_evens_and_odds(numbers):
    """
    Args:
     numbers(list_int32)
    Returns:
     list_int32
    """
    # Write your code here.
    size1=len(numbers)
    left=0
    right=size1-1
    if(left==right):    #single element
        return numbers
    while(left<=right):
        while(((numbers[left]%2)==0) & (left<size1-2)):   #move until even
            #print(f"{left},")
            left=left+1
        if(left==size1):   #reached end right away
            return numbers
        while(((numbers[right]%2==1)) & (right>=0)):  #move until odd
            right=right-1
        if(right==-1):      #reached end
            return numbers
        if(((numbers[left]%2)==1) & ((numbers[right]%2)==0) & (left<right)):   #swap
            c=numbers[right]
            numbers[right]=numbers[left]
            numbers[left]=c
        left=left+1
        right=right-1
        #print(f"left:{left},right:{right}")
    return numbers

numbers= [1, 2, 3, 4]
#numbers = [7]
#numbers = [1,3,5]
#numbers = [10,90]
print(f"Before sort:{numbers}")
numbers = segregate_evens_and_odds(numbers)
#print(f"remainder:{(3%2)}")
print(f"After sort:{numbers}")
