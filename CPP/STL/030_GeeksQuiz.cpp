#include<iostream>
using namespace std;

int main()
{
    int arri[]={1,2,3};
    int *ptri=arri;

    char arrc[]={1,2,3};
    char *ptrc=arrc;

    cout<<"sizeof arri "<<sizeof(arri)<<", ptri "<<sizeof(ptri)<<endl;
    cout<<"sizeof arrc "<<sizeof(arrc)<<", ptrc "<<sizeof(ptrc)<<endl;
    return 0;
}