/* Functions */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void swap(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

int main(void)
{
    int n1 = 15, n2 = 10;
    printf("n1=%d,n2=%d\n",n1,n2);
    swap(&n1,&n2);
    printf("n1=%d,n2=%d\n",n1,n2);

    return 0;
}
