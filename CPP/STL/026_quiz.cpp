#include<iostream>
using namespace std;

int fun(char* str1)
{
    char *str2=str1;
    while(*++str1);     // str1 moved to end of string, and hence empty
    cout<<str1<<endl;
    cout<<str2<<endl;
    return(str1-str2);  //ends up being length of original str1, since str1 became empty
}

int main()
{
    char *str = "GeeksQuiz";
    cout<<fun(str)<<endl;
    return 0;
}