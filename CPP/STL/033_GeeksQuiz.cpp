#include<iostream>
using namespace std;

int main()
{
    int array[5][5];
    cout<<(((void *)array==*array) && (*array==array[0]));
    return 0;
}
