#include<iostream>
using namespace std;
int main()
{
    string name;
    //cout<<"Enter name:";
    //cin>>name;
    //cout<<"Hi "<<name<<endl;

    string name1;
    getline(cin,name1);
    cout<<"Hi (full name with space) is "<<name1<<endl;
    return 0;
}