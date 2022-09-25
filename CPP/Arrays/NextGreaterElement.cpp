/* Next Greater Element */
/* Source: https://www.geeksforgeeks.org/next-greater-element/ */

/* Given an array, print the Next Greater Element (NGE) for every element. 
The Next greater Element for an element x is the first greater element on the right side of x in the array. Elements for which no greater element exist, consider the next greater element as -1. 

Example: 

Input: arr[] = [ 4 , 5 , 2 , 25 ]
Output:  4      –>   5
               5      –>   25
               2      –>   25
              25     –>   -1
Explanation: except 25 every element has an element greater than them present on the right side

Input: arr[] = [ 13 , 7, 6 , 12 ]
Output:  13      –>    -1
                7       –>     12
                6       –>     12
               12      –>     -1
Explanation: 13 and 12 don’t have any element greater than them present on the right side
*/

#include <vector>
#include <stack>
#include <iostream>

using namespace std;

void printArray(vector<int> nums)
{
    //int n = sizeof(nums)/sizeof(nums[0]);
    int n = nums.size();
    cout << "Array: Size:" << n << ": ";
    for (int i=0;i<n-1;i++)
    {
        cout << nums[i] << ",";
    }
    cout << nums[n-1] << endl;
}

int printStack(stack<int> stack1)
{
    cout << "Stack: ";
    for(int i=0;i<stack1.size();i++)
    {
        cout<< stack1.top() << " ";
        stack1.pop();
    }
    cout << endl;
    return 1;
}

vector<int> nextGreaterElement(vector<int> nums)
{
    vector<int> result;
    stack<int> myStk;
    myStk.push(nums[0]);
    printStack(myStk);
    for(int i=1;i<nums.size();i++)
    {
        cout<< "New Iteration" << endl;
        printStack(myStk);
        if(myStk.empty())
        {
            myStk.push(nums[i]);
            cout<< "Stack is empty! New stack now-";
            printStack(myStk);
            continue;
        }
        while(!myStk.empty() && printStack(myStk) && myStk.top()<nums[i])
        //while(!myStk.empty() && myStk.top()<nums[i])
        {
            //cout << "Result";
            //printStack(myStk);
            //result.push_back(myStk.top());
            cout << myStk.top() << " --> " << nums[i] << endl;
            myStk.pop();
        }
        myStk.push(nums[i]);
    }
    while(!myStk.empty())
    {
        result.push_back(-1);
        myStk.pop();
    }

    return result;
}

int main(void)
{
    vector<int> arr;
    arr.push_back(11);
    arr.push_back(9);
    arr.push_back(13);
    arr.push_back(21);
    arr.push_back(3);

    printArray(arr);
    vector<int> result=nextGreaterElement(arr);
    cout << "Result after NGE:" << endl;
    //printArray(result);

    return 0;
}