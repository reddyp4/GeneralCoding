/*
170. Two Sum III - Data structure design
Attempted
Easy
Topics
Companies
Design a data structure that accepts a stream of integers and checks if it has a pair of integers that sum up to a particular value.

Implement the TwoSum class:

TwoSum() Initializes the TwoSum object, with an empty array initially.
void add(int number) Adds number to the data structure.
boolean find(int value) Returns true if there exists any pair of numbers whose sum is equal to value, otherwise, it returns false.
 

Example 1:

Input
["TwoSum", "add", "add", "add", "find", "find"]
[[], [1], [3], [5], [4], [7]]
Output
[null, null, null, null, true, false]

Explanation
TwoSum twoSum = new TwoSum();
twoSum.add(1);   // [] --> [1]
twoSum.add(3);   // [1] --> [1,3]
twoSum.add(5);   // [1,3] --> [1,3,5]
twoSum.find(4);  // 1 + 3 = 4, return true
twoSum.find(7);  // No two integers sum up to 7, return false
 

Constraints:

-105 <= number <= 105
-231 <= value <= 231 - 1
At most 104 calls will be made to add and find.

*/

/*
Traditional two sum: left and right pointers, if sorted easier (sorting: O(logn))
add in sorted way, find becomes easier
Vector is one way, however iteration is time consuming, fails for bigger datasets
*/
#include<vector>
class TwoSum {
public:
    vector<int> data;
    int datamax=0;
    TwoSum() {
        data = {};
        datamax = -pow(10,5)-1;
    }
    
    void print_data(void)
    {
        cout<<"data:";
        for(int i=0;i<data.size();i++)  cout<<data[i]<<",";
        cout<<endl;
    }
    void add(int number) {
        if(data.empty())  {data.push_back(number);return;}
        if(number>data.back())
        {
            data.push_back(number);
            return;
        }
        int i=0;
        while(data[i]<number)   i++;
        //keep it sorted
        data.insert(data.begin()+i,number);
    }
    
    bool find(int value) {
        int left=0,right=0;
        print_data();
        while(left<data.size())
        {
            right=left+1;
            while(right<data.size() && (data[right]<=(value-data[left])))
            {
                //cout<<"Sum:"<<value<<",Left:"<<data[left]<<",Right:"<<data[right]<<endl;
                if(data[right]==(value-data[left])) return true;
                right++;
            }
            left++;
        }
        return false;
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */

 //HASH-MAP SOLUTION
 /*
hashmap solution:
*/

class TwoSum {
public:
    map<int,int> data;  //value-count
    TwoSum() {
        
    }
    
    void add(int number) {
        if(data.count(number)==1)   data[number]++;
        else    data[number]=1;
    }
    
    bool find(int value) {
        for(auto key:data)
        {
            int other=value-key.first;
            if(data.count(other)==1)
            {
                //check not same number and only number
                if(other!=key.first)  return true;
                if(other==key.first)
                    if(key.second>1)
                        return true;
            }
        }
        return false;
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */