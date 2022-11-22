#include<iostream>
using namespace std;

int main()
{
    int var;
    //void *ptr = &var;   // void pointer cannot be assigned, correct way: *(int*)(&var)
    int *ptr = (&var);
    *ptr = 5;
    cout<<var<<" "<<*ptr<<endl;

    return 0;
}