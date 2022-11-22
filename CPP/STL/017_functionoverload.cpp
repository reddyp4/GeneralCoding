/**
 * @file 017_functionoverload.cpp
 * @author Patel Reddy (reddynisky145@gmail.com)
 * @brief function overload can help avoiding writing multiple functions
 * function overload cannot be on return type
 * any function without arguements can cause compile error
 * @version 0.1
 * @date 2022-11-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
using namespace std;

int myMax(int x, int y)
{
    return(x>y)? x: y;
}
int myMax(int x, int y, int z)
{
    return myMax(myMax(x,y),z);
}
int main()
{
    int a=10,b=20,c=30;
    cout<<myMax(a,b)<<endl;
    cout<<myMax(a,b,c)<<endl;
    return 0;
}