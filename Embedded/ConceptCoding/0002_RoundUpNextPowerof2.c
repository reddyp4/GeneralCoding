/*
Write code in C to "round up" any number to the next "power of 2", unless the number is already a power of 2. For example, 5 rounds up to 8, 42 rounds up to 64, 128 rounds to 128. 

n =      101011    10
n-1 =    101010    01
n&(n-1) -> turn off the last bit

*/

int roundUp(int a)
{
    printf("number:%d\n",(a&(a-1)));
    if(a&(a-1)==0)
        return a;            //single 1 bit
    int prevA=a;
    while(a&(a-1)!=0)     //continue to turn off all the bits (from rightside) until single bit
    {
        a=(a&(a-1));
    }
    return (a<<1U);
}

