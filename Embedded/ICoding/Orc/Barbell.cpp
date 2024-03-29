#include<iostream>
#include<vector>
#include<cmath>
//from name
using namespace std;

//Use all weight combinations
int maxWeight1(vector<int> &weights, int maxCapacity)
{
    int size1 = weights.size();
    int MAX_ITER = pow(2,size1);
    int maxSum=0, currentSum;
    for (int i=0;i<MAX_ITER;i++)
    {
        currentSum = 0;
        for(int j=0;j<size1;j++)
        {        
            int choice = ((i&&(0x1<<j))>0);
            cout<<"i:"<<i<<",j:"<<j<<",choice:"<<choice;
            currentSum += (choice*weights[j]);
        }
        currentSum = (currentSum>maxCapacity)? 0: currentSum;
        maxSum = (maxSum>currentSum)? maxSum:currentSum;
    }
    //cout << "size:" <<size1<<",maxiter:"<<MAX_ITER<<endl;
    return maxSum;
}

int main()
{
    //barbell weights
    int size = 5;
    std::vector<int> weights = {7,1}; //,5,6,2};
    //max capacity
    int maxCapacity = 7;
    //reach the maxm
    cout << "Max weight achieved: " << maxWeight1(weights, maxCapacity) << endl;
    return 0;
}
