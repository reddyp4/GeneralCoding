/*

Define a pointer to an int, pointer to a pointer to an int, an array of 10 int pointers, pointer to an array of 10 ints, pointer to a function which returns an int and takes an int as an argument. Consider the following:



Associativity and precedence rules
Storing addresses of data locations with an index
Implementing device driver entry points

*/
//int *a;
//int **a;
//int (*a)[10];
//int *a[10];

#include <iostream>
using namespace std;

int sum(int (*a)[10])
{
    int *p=*a;
    int sum=0;
    for(int i=0;i<10;i++)
    {
        sum+=(*a)[i];
    }
    /*
    while(p!=NULL)  // will not work - since not sure if end of array is a null
    {
        sum+=*p;
        p++;
    }*/
    cout << "sum: " << sum << endl;
    return sum;
}

int main(void)
{
    int a[10] = {1,3,5,7,9,2,4,6,8,10};
    int sum1 = sum(&a);
    return 0;
}