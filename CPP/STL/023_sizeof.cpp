#include<iostream>
using namespace std;

//arguements of sizeof are not executed

int main()
{
    cout<<sizeof(printf("hello"))<<endl;
    return 0;
}