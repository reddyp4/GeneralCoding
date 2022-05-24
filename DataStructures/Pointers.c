/* Pointers */
/* Allow you to use the heap memory, vs stack typically used by a program */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(void)
{
    int a=10;
    int b[3] = {1,2,3};
    int *p;
    p = &a;
    printf("a=%d,*a=%d\n",a,p);
    // Pointer increment by 4 bytes
    printf("b[0]=%d,b[1]=%d\n",&(b[0]),&(b[1]));

    int *q;
    q = (int*)malloc(5*sizeof(int));
    q[0]=1;q[2]=2;q[3]=3;q[4]=4;q[5]=5;
    printf("q[0]=%d,q[1]=%d\n",&(q[0]),&(q[1]));
    // Pointer is 4-bytes in a 32-bit architecture, 8-bytes in 64-bit architecture

    //release memory from malloc
    free(q);

    return 0;
}