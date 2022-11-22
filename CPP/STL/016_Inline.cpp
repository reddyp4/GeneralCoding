#include <iostream>
using namespace std;

/**
 * @brief inline
 * inline is used to insert function as is
 * inline is better than macro, (1) macro doesnthave type checking, (2) brackets can cause issue
 * But using inline too much may increase the binary file size
 * 
 */
inline int getMax(int x,int y)
{
    return(x>y)? x: y;
}

int main()
{
    cout<<getMax(10,20)<<endl;
    return 0;
}
