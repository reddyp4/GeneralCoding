#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    bool a = true;
    cout << "Value of a:"<<a<<endl;
    cout<<"Value of a:"<<std::boolalpha<<a<<endl;
    cout<<"Value of a:"<<std::noboolalpha<<a<<endl;

    //Printing in different bases
    int x=10,y=20;
    cout<<"a:"<<a<<" b:"<<y<<endl;
    cout<<"a:"<<std::showbase<<::hex<<x<<" b:"<<y<<endl;
    cout<<"a:"<<std::showbase<<std::dec<<x<<" b:"<<y<<endl;
    cout<<"a:"<<std::showbase<<std::oct<<x<<" b:"<<y<<endl;

    //Printing in alignment, width
    //only setw, setfill need iomanip library
    cout<<"x:"<<std::setw(5)<<std::setfill('0')<<std::right<<x<<endl;
    return 0;
}
