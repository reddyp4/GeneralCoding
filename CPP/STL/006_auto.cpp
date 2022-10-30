#include <iostream>
#include <typeinfo>
using namespace std;

int main()
{
    auto a = 10;
    auto b = 10.5;
    cout << a << " " << b << endl;
    cout << typeid(a).name() << " " << typeid(b).name() << endl;
    return 0;
}