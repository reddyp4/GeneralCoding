/*
41. First Missing Positive
Solved
Hard
Topics
conpanies icon
Companies
Hint
Given an unsorted integer array nums. Return the smallest positive integer that is not present in nums.

You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.

 

Example 1:

Input: nums = [1,2,0]
Output: 3
Explanation: The numbers in the range [1,2] are all in the array.
Example 2:

Input: nums = [3,4,-1,1]
Output: 2
Explanation: 1 is in the array but 2 is missing.
Example 3:

Input: nums = [7,8,9,11,12]
Output: 1
Explanation: The smallest positive integer 1 is missing.
 

Constraints:

1 <= nums.length <= 105
-231 <= nums[i] <= 231 - 1
*/
/*
Bruteforce
    Sort
    Check first positive digit? How?
    Binary search for index i, so [i]>0, [i-1]<0
*/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if(nums.size()==1)  {
            if(nums[0]<=0)   return 1;
            if(nums[0]==1)  return 2;
            return 1;
        }
        sort(nums.begin(),nums.end());
        /* all negative numbers */
        if(nums[nums.size()-1]<0)   return 1;
        /* all positive numbers, but more than 1 */
        if(nums[0]>1)   return 1;
        /* Now binary search for i, [i-1]<0 and [i]>0 */
        int s=0,len1=nums.size(),e=len1-1,m=(s+e)/2,i=0;
        bool foundi=false,print=false;
        if(print)   {
            cout<<"Search foundi"<<endl;
        }
        while(!foundi && (m!=s))    {
            if(print)   {
                cout<<"s:"<<s<<",nums[s]:"<<nums[s]<<",m:"<<m<<",nums[m]:"<<nums[m]<<",e:"<<e<<",nums[e]:"<<nums[e]<<endl;
                cout<<"nums[m-1]:"<<nums[m-1]<<",nums[m]:"<<nums[m]<<",nums[m+1]:"<<nums[m+1]<<endl;
            }
            if(nums[m-1]<0 && nums[m]>=0)    {
                i=m;
                foundi=true;
                if(print)   cout<<"Found m"<<endl;
            }
            else if(nums[m]<0 && nums[m+1]>=0)   {
                i=m+1;
                foundi=true;
                if(print)   cout<<"Found m+1"<<endl;
            }
            else    {
                if(nums[m]<0)   {
                    //go right
                    s=m;
                }
                else    {
                    //go left
                    e=m;
                }
                m=(s+e)/2;
            }
        }
        if(!foundi) {
            if(m!=0 && nums[m-1]<0 && nums[m]>0)    {
                i=m;
                foundi=true;
            }
            else if(nums[m]<0 && nums[m+1]>0)   {
                i=m+1;
                foundi=true;
            }
        }
        if(print)   {
            cout<<"Finished foundi:"<<endl;
            cout<<"foundi:"<<foundi<<",i:"<<i<<",nums[i]:"<<nums[i]<<endl;
        }
        /* if foundi and [i]!=1, return 1*/
        /* else, from [i]to[len1-1] find i */
        if(foundi && nums[i]>1)  return 1;
        if(print)   {
            cout<<"Higher positive numbers!"<<endl;
        }
        /* criteria for i, [i]-[i-1]>1 */
        /* return [i-1]+1 */
        s=i;e=len1-1;foundi=false;
        i=s;
        if(print)   {
            cout<<"s:"<<s<<",nums[s]:"<<nums[s]<<",e:"<<e<<",nums[e]:"<<nums[e]<<",i:"<<i<<",nums[i]:"<<nums[i]<<endl;
        }
        while(i<e) {
            if(print)   cout<<"i:"<<i<<",nums[i]:"<<nums[i]<<endl;
            if(nums[i+1]-nums[i]>1) {
                return nums[i]+1;
            }
            i++;
        }
        return nums[i]+1;
    }
};

/*
Runtime
16
ms
Beats
24.39%
Analyze Complexity
Memory
55.05
MB
Beats
47.24%
*/