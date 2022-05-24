/* References */
// Code is not working in C!

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(void)
{
    int a=10;
    int &r = a;

    printf("a=%d,&r=%d\n",a,r);

    return 0;
}