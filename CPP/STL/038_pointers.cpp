/**
 * @file 038_pointers.cpp
 * @author Patel (you@domain.com)
 * @brief Pointers
 * @version 0.1
 * @date 2022-11-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<iostream>
using namespace std;

int main()
{
    char arr[]={'g','f','g'};
    char *ptr = arr;
    cout<<"Size of arr[]:"<<sizeof(arr)<<endl;
    cout<<"Size of ptr:"<<sizeof(ptr)<<endl;    // size of pointer is 8 bytes

    int arr1[]={10,20,30};
    int *ptr1=arr1;
    ++*ptr1;        //precedence of ++ and * is same, go from left to right ++(*ptr1) -> increment value
                    // pointed by ptr1
    *ptr1++;         //postfix ++ higher precedence than *, like *(ptr++) -> ptr moves to 20
    *++ptr1;        // prefix, * same precedence, hence *(++ptr1), ptr should move
    cout<<"Size of ptr1:"<<sizeof(ptr1)<<endl;
    cout<<"Arr1:"<<arr1[0]<<" "<<arr1[1]<<" "<<arr1[2]<<", *ptr1:"<<*ptr1<<endl;
    return 0;
}