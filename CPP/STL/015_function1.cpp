#include <iostream>
using namespace std;

// Default arguements must be
// 1) At end
// 2) Preferred way to say at declaration

void printDetails(int id, string name = "NA", string address = "NA")
{
    cout<<"Id is "<<id<<endl;
    cout<<"Name is "<<name<<endl;
    cout<<"Address is "<<address<<endl;
}

int main()
{
    printDetails(101,"Anagha","New York");
    printDetails(102,"Haarika");
    printDetails(103);
    return 0;
}