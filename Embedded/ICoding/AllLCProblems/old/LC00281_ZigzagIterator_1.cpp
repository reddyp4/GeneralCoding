/*
281. Zigzag Iterator
Solved
Medium
Topics
Companies

Given two vectors of integers v1 and v2, implement an iterator to return their elements alternately.

Implement the ZigzagIterator class:

    ZigzagIterator(List<int> v1, List<int> v2) initializes the object with the two vectors v1 and v2.
    boolean hasNext() returns true if the iterator still has elements, and false otherwise.
    int next() returns the current element of the iterator and moves the iterator to the next element.

 

Example 1:

Input: v1 = [1,2], v2 = [3,4,5,6]
Output: [1,3,2,4,5,6]
Explanation: By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,3,2,4,5,6].

Example 2:

Input: v1 = [1], v2 = []
Output: [1]

Example 3:

Input: v1 = [], v2 = [1]
Output: [1]

 

Constraints:

    0 <= v1.length, v2.length <= 1000
    1 <= v1.length + v2.length <= 2000
    -231 <= v1[i], v2[i] <= 231 - 1

 

Follow up: What if you are given k vectors? How well can your code be extended to such cases?

Clarification for the follow-up question:

The "Zigzag" order is not clearly defined and is ambiguous for k > 2 cases. If "Zigzag" does not look right to you, replace "Zigzag" with "Cyclic".

Follow-up Example:

Input: v1 = [1,2,3], v2 = [4,5,6,7], v3 = [8,9]
Output: [1,4,8,2,5,9,3,6,7]


*/

/*
Method1: Bruteforce, have a bool/counter to reduce and check
Method2: make a Q

*/

class ZigzagIterator {
private:
public:
    int index;
    int len;
    vector<int> result;

    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        int len1=v1.size(),len2=v2.size(),i=0,j=0,iter=1;
        while(i<len1 && j<len2)
        {
            if(iter==1) {result.push_back(v1[i]);i++;}
            else    {result.push_back(v2[j]);j++;}
            iter=1-iter;
        }
        while(i<len1)   {result.push_back(v1[i]);i++;}
        while(j<len2)   {result.push_back(v2[j]);j++;}
        len=len1+len2;
        index=0;
    }

    int next() {
        if(index<len)   return result[index++];
        return(0);
    }

    bool hasNext() {
        if(index<len)   return true;
        return false;
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
/*
Runtime 9ms Beats28.82% Analyze Complexity
Memory 11.99MB Beats27.08%
*/