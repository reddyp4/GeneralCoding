/*
170. Two Sum III - Data structure design
Solved
Easy
Topics
conpanies iconCompanies

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
Bruteforce: Add to a vector, every find will check in the vector for every i,j - On2
Slightly Better: Add to a map of vectors. For every key, search if the complement exists - On? Corner case, value and only one occurence of half
Modified of Bruteforce: Add in sorted fashion.

Corner case 
    value-key.first<INT_MIN
    value-key.first>INT_MAX
*/

class TwoSum {
public:
    /* Bruteforce */
    map<int,int> myMap;
    TwoSum() {
        // Nothing to do here
    }
    
    void add(int number) {
        if(myMap.count(number)>0)   myMap[number]++;
        else myMap[number]=1;
    }
    
    bool find(int value) {
        for(auto &key:myMap)    {
            if((key.first>0 && INT_MIN+key.first>value));
            else if((key.first<0 && INT_MAX+key.first<value));
            else if(myMap.count(value-key.first)>0)  {
                if(value-key.first==key.first)  {
                    if(key.second>=2)   return true;
                    else return false;
                }
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

/*
Runtime
79ms
Beats22.22%
Analyze Complexity
Memory
34.88MB
Beats49.46%
*/