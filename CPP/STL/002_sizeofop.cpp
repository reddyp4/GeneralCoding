#include <iostream>
using namespace std;

int main(void)
{
    // sizeof is evaluated at compile time and not run time 
    cout << sizeof(int) << endl;
    cout << sizeof(char) << endl;
    cout << sizeof(long long) << endl;
    cout << sizeof(float) << endl;
    cout << sizeof(10LL) << endl;
    cout << sizeof(10-5) << endl;
    return 0;
}