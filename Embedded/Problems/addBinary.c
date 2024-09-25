#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char* addBinary(char * a, char * b){
    /* Two pointer approach again? */
    /* Convert each string to integer and add and convert to string */
    int a1,b1,sum1,k;
    char *final;
    char buffer[20];
    a1=strtol(a,NULL,2);
    b1=strtol(b,NULL,2);
    sum1=a1+b1;
    /* Convert to binary string*/
    k=0;
    while(sum1!=0)
    {
        buffer[k]=(sum1%2);
        sum1=(int)(sum1/2);
    }
    final = &(buffer[0]);
    return final;
}