/* Find every odd occuring element in an array where every element occurs twice */
/* {2,2,3,3,4} = 4*/
/* {2,2,3,3,4,4,4} = 4*/

#include<stdio.h>
#include<stdint.h>

int main(void)
{
    int arr[]={2,3,4,2,3};
    int sum=0;
    for(int i=0;i<5;i++)
    {
        sum=sum^arr[i];
    }
    printf("%d\n",sum);
    return 0;
}

