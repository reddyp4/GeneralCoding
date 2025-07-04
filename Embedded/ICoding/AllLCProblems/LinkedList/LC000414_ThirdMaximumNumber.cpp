/*
414. Third Maximum Number
Solved
Easy
Topics
conpanies icon
Companies
Given an integer array nums, return the third distinct maximum number in this array. If the third maximum does not exist, return the maximum number.

 

Example 1:

Input: nums = [3,2,1]
Output: 1
Explanation:
The first distinct maximum is 3.
The second distinct maximum is 2.
The third distinct maximum is 1.
Example 2:

Input: nums = [1,2]
Output: 2
Explanation:
The first distinct maximum is 2.
The second distinct maximum is 1.
The third distinct maximum does not exist, so the maximum (2) is returned instead.
Example 3:

Input: nums = [2,2,3,1]
Output: 1
Explanation:
The first distinct maximum is 3.
The second distinct maximum is 2 (both 2's are counted together since they have the same value).
The third distinct maximum is 1.
 

Constraints:

1 <= nums.length <= 104
-231 <= nums[i] <= 231 - 1

*/

/*
Maintain max1, max2, max3 and distinctness by simple check
    if new number>max1, push max2=max1, max3=max2, max1=new
    if max1>new>max2, push max3=max2
    this is complex to code
Instead maintain a queue, insert element if not present, pop from end if size>3
    Variability use linked list
*/
typedef struct node {
    int val;
    struct node* next;
};

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        node max3,max2,max1;
        int size1=0,len1=nums.size(),i=0;
        map<int,bool> seen;
        max3.val=nums[0];size1=1;seen[nums[0]]=true;
        bool print=false;
        //Find max2
        i=1;
        if(print)   cout<<"i:"<<i<<",max3:"<<max3.val<<endl;
        while(i<len1 && seen[nums[i]]) i++;
        if(i==len1) return max3.val;    //no more values
        seen[nums[i]]=true;
        if(nums[i]>max3.val)    {
            max2.val=max3.val;
            max3.val=nums[i];
        }
        else    max2.val=nums[i];
        size1++;
        if(print)   cout<<"i:"<<i<<",max2:"<<max2.val<<"max3:"<<max3.val<<endl;
        //Repeat for max1
        i++;
        while(i<len1 && seen[nums[i]]) i++;
        if(i==len1) return max3.val;
        seen[nums[i]]=true;
        if(nums[i]>max3.val)    {
            max1.val=max2.val;
            max2.val=max3.val;
            max3.val=nums[i];
        }
        else if(nums[i]>max2.val)  {
            max1.val=max2.val;
            max2.val=nums[i];
        }
        else    max1.val=nums[i];
        if(print)   cout<<"i:"<<i<<",max1:"<<max1.val<<",max2:"<<max2.val<<",max3:"<<max3.val<<endl;
        i++;
        size1++;
        //Now loop rest of array
        while(i<len1) {
            if(seen[nums[i]])   {}
            else if(nums[i]<max1.val)    {seen[nums[i]]=true;}
            else if(nums[i]<max2.val)   {max1.val=nums[i];}
            else if(nums[i]<max3.val)   {max1.val=max2.val;max2.val=nums[i];}
            else if(nums[i]>max3.val)   {max1.val=max2.val;max2.val=max3.val;max3.val=nums[i];}
            seen[nums[i]]=true;
            i++;
            size1++;
        }
        if(print)   cout<<"i:"<<i<<",max1:"<<max1.val<<",max2:"<<max2.val<<",max3:"<<max3.val<<endl;
        if(size1>=3) return max1.val;
        return max3.val;
    }
};
/*
Runtime
3
ms
Beats
34.17%
Analyze Complexity
Memory
14.33
MB
Beats
27.83%
*/