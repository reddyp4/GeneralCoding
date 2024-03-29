/*
Problem: 
Ollie is new to the gym and is figuring out the maximum weights she can lift. 
The maximum capacity of the barbell is given as maxCapacity. 
Each barbell plate has a weight, given by weights[i]. 
Now Ollie has to select as many plates as she can but the total 
weight of the selected plates should not exceed maxCapacity. 
What is the maximum weight of plates Ollie can add to the barbell?
For example, given barbell plates of weights 1, 3 and 5 lbs and a barbell of 
maxCapacity 7 lbs, the right plates to insert would be 1 and 5 lbs making 
the right answer 6.

Constraints

1 ≤ n ≤ 42 //size of array of weights
1 ≤ maxCapacity ≤ 10^9 
1 ≤ weights[i][ ]≤ 10^9

int computeMaxLiftingCapacity(vector <int> weights, int maxCapacity){

}
*/

#include<iostream>
#include<vector>
#include<cmath>
//from name
using namespace std;

//Use all weight combinations, polynomial order
int maxWeight1(vector<int> &weights, int maxCapacity)
{
    int size1 = weights.size();
    int MAX_ITER = pow(2,size1);
    int maxSum=0, currentSum, choice=0;
    for (int i=0;i<MAX_ITER;i++)
    {
        currentSum = 0;
        for(int j=0;j<size1;j++)
        {        
            choice = !((i&(0x1<<j))==0);
            //cout<<"i:"<<i<<",j:"<<j<<",choice:"<<choice<<endl;
            currentSum += (choice*weights[j]);
        }
        currentSum = (currentSum>maxCapacity)? 0: currentSum;
        maxSum = (maxSum>currentSum)? maxSum:currentSum;
    }
    //cout << "size:" <<size1<<",maxiter:"<<MAX_ITER<<endl;
    return maxSum;
}

//Return maxPossible given weight, maxCap, earlier maxPossible
void getMaxPossible(int weight, int *maxPossible, int maxCapacity)
{
    if(weight>maxCapacity)  return; //nothing to do
    if(weight>*maxPossible && weight<maxCapacity)
    {
        *maxPossible=weight;
        return;
    }
    return;
}
//Optimal way: Keep making the array of possible weights, and take maximum
int maxWeight2(vector<int> &weights, int maxCapacity)
{
    uint64_t i;
    int maxPossible=0,maxValue=0,minValue=INT_MAX;
    //Initiate boolean array of size of maxCapacity
    vector<bool> possible(maxCapacity+1,false);
    uint64_t size1=weights.size();
    //Initiate the array
    for(i=0;i<size1;i++)
    {
        getMaxPossible(weights[i],&maxPossible,maxCapacity);
        possible[weights[i]]=true;
    }
    if(maxPossible==maxCapacity)    return maxPossible;
    //Now count rest of array
    for(int i=0;i<maxCapacity+1;i++)
    {
        if(possible[i])    //if set, set the next possible values
        {            
            for(int j=0;j<size1;j++)
            {
                uint64_t value=i+weights[j];
                possible[value]=true;
                //check new maxPossible
                getMaxPossible(value,&maxPossible,maxCapacity);
            }
        }    
    }
    return maxPossible;
}
int main()
{
    //barbell weights
    std::vector<int> weights = {1,5,4};
    //max capacity
    int maxCapacity = 7;
    //reach the maxm
    int maxWeightVal1 = maxWeight1(weights, maxCapacity);
    cout << "Max weight1 achieved: " <<  maxWeightVal1 << endl;
    int maxWeightVal2 = maxWeight2(weights, maxCapacity);
    cout << "Max weight2 achieved: " <<  maxWeightVal2 << endl;
    return 0;
}
