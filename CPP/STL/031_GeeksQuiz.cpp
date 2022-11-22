#include<iostream>
using namespace std;

int main()
{
    float arr[5]={12.5, 10.0, 13.5, 90.5, 0.5};
    float *ptr1 = &arr[0];                  // ptr1 points to first element
    float *ptr2 = ptr1+3;                   // ptr2 by three floating numbers - points to 90.5

    cout<<*ptr2<<" "<<(ptr2-ptr1)<<endl;    //ptr2-ptr1 = 3, since this is difference in address values
    return 0;
}