'''
Knight's Tour On A Phone Keypad
Given a phone keypad as shown below:

1 2 3
4 5 6
7 8 9
– 0 –

How many different phone numbers of given length can be formed starting from the given digit? The constraint is that the movement from one digit to the next is similar to the movement of the Knight in chess.

For example, if we are at 1, then the next digit can be either 6 or 8; if we are at 6 then the next digit can be 1, 7 or 0.

Repetition of digits is allowed, e.g. 1616161616 is a valid number.
There is no need to list all possible numbers, just find how many they are.
Find a polynomial-time solution, based on Dynamic Programming.

Example One
{
"start_digit": 1,
"phone_number_length": 2
}
Output:

2
Two possible numbers of length 2: 16, 18.

Example Two
{
"start_digit": 1,
"phone_number_length": 3
}
Output:

5
The possible numbers of length 3: 160, 161, 167, 181, 183

Notes
There are two input parameters: start_digit and phone_number_length, denoting the starting digit and the required length respectively.
Output is a long integer denoting the total number of valid phone numbers that can be formed.
Constraints:

0 <= start_digit <= 9
1 <= phone_number_length <= 30
'''


'''
def count_phone_numbers_of_given_length(start_digit, phone_number_length):
    Args:
     start_digit(int32)
     phone_number_length(int32)
    Returns:
     int64
    """
    # Write your code here.
    #maintain count of next numbers, maintain count of next digits
    keys={1:[6,8],2:[7,9],3:[4,8],4:[3,9,0],5:[],6:[0,1,7],7:[2,6],8:[1,3],9:[2,4],0:[4,6]}
    if(phone_number_length==1):
        return len(keys[start_digit])
    count=[0]*10
    #Bruteforce keep track of all digits
    '''
    '''
    digits=[]
    digits.append(start_digit)
    print("digits:",digits)
    total=1
    for i in range(1,phone_number_length):
        options=[]
        for j in range(len(digits)):
            options.extend(keys[digits[j]])
        digits=(options)
        print("digits:",digits)
        total+=len(digits)
    return len(options)
'''

#v2: Maintain a list of indices 0 to 9, that has a count of how many times digit appears
def count_phone_numbers_of_given_length(start_digit, phone_number_length):
    """
    Args:
     start_digit(int32)
     phone_number_length(int32)
    Returns:
     int64
    """
    # Write your code here.
    if(phone_number_length==1):
        return len(keys[start_digit])
    keys={0:[4,6],1:[6,8],2:[7,9],3:[4,8],4:[0,3,9],5:[],6:[0,1,7],7:[2,6],8:[1,3],9:[2,4]}
    digits=[0]*10
    digits[start_digit]=1
    while(phone_number_length>1):
        #print("digits:",digits)
        newDigits,i=[0]*10,0
        while(i<10):
            if(digits[i]!=0):
                #print("digits[i]:",keys[i])
                for k in keys[i]:
                    newDigits[k]+=digits[i]
            i+=1
        #print("newDigits:",newDigits)
        for i in range(10):
            digits[i]=newDigits[i]
        phone_number_length-=1
    return sum(digits)



'''
Initial idea is to maintain the last known list of digits, so we can get n+1
However this list grows in polynomial fashion

Since the digits are only 0 to 9, now we can improve by maintain a count list of digits
newDigit count is created

[1,2]=2
[1,3]=5
[6,20]=9068032
[6,30]=35689414656
[9,13]=19520
[1,30]=22057271296
[2,8]=272
[8,29]=8425127936
'''