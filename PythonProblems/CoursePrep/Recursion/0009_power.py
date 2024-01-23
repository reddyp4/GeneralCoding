'''
Power
Given a base a and an exponent b. Your task is to find ab. The value could be large enough. So, calculate ab % 1000000007.

Example
{
"a": 2,
"b": 10
}
Output:

1024
Notes
Constraints:

0 <= a <= 104
0 <= b <= 109
a and b together won't be 0
'''

def power(a,b):
    if(b==1):
        return a
    getVal = power(a,int(b/2))
    getVal = getVal%1000000007
    if(b%2==0):
        getVal = (getVal*getVal)%1000000007
    else:
        getVal = (getVal*getVal*a)%1000000007
    return getVal
        

def calculate_power(a, b):
    """
    Args:
     a(int64)
     b(int64)
    Returns:
     int32
    """
    # Write your code here
    if(a==0):
        return 0
    if(a==1 or b==0):
        return 1
    ans=power(a,b)
    return ans
