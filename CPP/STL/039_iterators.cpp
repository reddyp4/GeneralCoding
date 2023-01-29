/* Iterators */
// CPP program illustrating
// iterators
#include <iostream>
#include <vector>
using namespace std;

// Driver Method
int main()
{
    // Sample vector container
    vector<int> v = { 10, 20, 30, 40, 50 };

    // Creating an iterator
    // auto i; -> this can also be used to
    // avoid the long statement
    // i points to the first element
    vector<int>::iterator i = v.begin();

    // Prints the value at i
    cout << (*i) << " ";

    // Increments i by 1
    i++;

    // Prints the value at next position
    cout << (*i) << " ";

    // Now i points to the element beyond
    // the alst element at the vector
    i = v.end();

    // Decrements i by 1
    i--;

    // Prints the value at i
    cout << (*i) << " ";
    return 0;
}
