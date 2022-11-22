#include<iostream>
using namespace std;

int main()
{
    struct site {
        char name[] = "GeeksQuiz";      //Cannot initialize during declaration
        int no_pages = 200;             //Cannot initialize during declaration
    };
    struct site *ptr;
    cout<<ptr->no_pages<<" "<<ptr->name<<endl;
    return 0;
}
