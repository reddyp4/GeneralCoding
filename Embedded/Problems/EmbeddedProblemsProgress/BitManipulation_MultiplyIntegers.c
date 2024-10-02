/* Multiply x*y, followup: without using + */
/* Option1: continuous add */
/* Option2: x*2^bit and shift y*/
/* Option3: left shift x and right shift y, add x if last bit is 1 */
#include<stdint.h>
#include<stdio.h>

uint16_t product(uint8_t x, uint8_t y)
{
    uint16_t answer=0;
    while(y)
    {
        printf("x:%u, y:%u, answer:%u\n",x,y,answer);
        if(y&0x1)   answer+=x;
        x=x<<1;
        y=y>>1;
    }
    return answer;
}

int main(void)
{
    uint8_t x=5,y=6;
    printf("Number1:%u, Number2:%u, Product:%u\n",x,y,product(x,y));
    return 0;
}