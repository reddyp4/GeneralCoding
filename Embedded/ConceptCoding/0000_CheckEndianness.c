/* # Write a function to see if a given processor is a little endian or big endian

#Little endian: MSB-most siginificant byte sits at index 0:(AB) 0xABCD EFGH = 0xABCDEFGH
#Big endian:MSB sits at last index: CD is MSB, 0xABCD EFGH = 0xCDAB GHEF

 */
#include<stdio.h>
#include<stdint.h>

int checkEndian(void)
{
    int seq = 0x1;  //test data
    char *ptr;      //ptr to this data
    ptr=(char *)&seq;   //pointing
    if(*ptr==seq)
        printf("Little Endian\n");
    else
        printf("Big Endian\n");
    return 0;
}

int main(void)
{
    checkEndian();
    return 1;
}