#include <iostream>


using namespace std;

int main()
{
#if 0
    string name;
    cout<<"Enter your name:";
    // single string
    //cin>>name;
    //mulitple strings
    getline(cin,name);
    cout<<"Welcome Mr/Miss "<<name;
#endif

#if 0
    float base, height;
    cout<<"Enter base, height";
    cin>>base>>height;
    cout<<"Area = "<<(base*height)<<endl;
#endif

#if 0
    //collection of objects=enum, user defined datatypes
    enum day {mon=1, tue, wed, thu, fri, sat, sun};
    day day1 = mon;
    cout<<day1<<endl;
#endif

    return 0;
}