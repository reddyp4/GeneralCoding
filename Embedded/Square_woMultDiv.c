/* Find square without multiplication & division */
#include <stdio.h>
#include <stdint.h>

int square_num(int num)
{
    int orig_num = num;
    int sum=0;
    while(num)
    {
        sum = sum << 2;
        if(sum&0x01)
            sum+=orig_num;
        num = num >> 1;
    }
}

void main(void)
{
    int num=5;
    printf("square=%d\n",square_num(num));
}
/*
5*5 = (5*8)+(5*2)=
num = 5 = 101 = orig_num
orig_num        num         sum 
5(101)          5(101)      */
