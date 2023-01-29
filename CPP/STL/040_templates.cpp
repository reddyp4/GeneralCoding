// CPP program illustrating templates
#include <iostream>
using namespace std;

// This can also be written as
// template <class T>
template <typename T>

// Function template
T myMax(T x, T y)
{
    return (x > y) ? x : y;
}

// Drivers Method
int main()
{
    // This function call creates a function
    // where all the T's are replaced with int
    cout << myMax<int>(3, 7) << endl;

    // This function call creates a function
    // where all the T's are replaced with char
    cout << myMax<char>('c', 'g') << endl;
    
    return 0;
}
