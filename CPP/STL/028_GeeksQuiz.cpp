#include<iostream>
using namespace std;

typedef struct t{
    short s[5];
    union {
        float x;
        long z;
    } u;
} T;
T T1;

int main()
{
    cout<<sizeof(T1)<<endl;
    return 0;
}