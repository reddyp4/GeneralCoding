/*
692. Top K Frequent Words
Solved
Medium
Topics
conpanies icon
Companies
Given an array of strings words and an integer k, return the k most frequent strings.

Return the answer sorted by the frequency from highest to lowest. Sort the words with the same frequency by their lexicographical order.

 

Example 1:

Input: words = ["i","love","leetcode","i","love","coding"], k = 2
Output: ["i","love"]
Explanation: "i" and "love" are the two most frequent words.
Note that "i" comes before "love" due to a lower alphabetical order.
Example 2:

Input: words = ["the","day","is","sunny","the","the","the","sunny","is","is"], k = 4
Output: ["the","is","sunny","day"]
Explanation: "the", "is", "sunny" and "day" are the four most frequent words, with the number of occurrence being 4, 3, 2 and 1 respectively.
 

Constraints:

1 <= words.length <= 500
1 <= words[i].length <= 10
words[i] consists of lowercase English letters.
k is in the range [1, The number of unique words[i]]
 

Follow-up: Could you solve it in O(n log(k)) time and O(n) extra space?
*/
/*
Map->vector of pairs->sort->make result vector
lexicographical means smaller string comes first
*/
class Solution {
public:
    static bool comp(pair<string,int>&a,pair<string,int>&b)    {
        if(a.second!=b.second) return a.second>b.second;
        return a.first<b.first;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        int i,j;
        vector<string> result;
        map<string,int> occur;
        /* Map occurence map */
        for(i=0;i<words.size();i++) occur[words[i]]++;
        /* Make vector of pairs */
        vector<pair<string,int>> vec;
        for(auto &key:occur)    vec.push_back(key);
        /* Sort vector of pairs */
        sort(vec.begin(),vec.end(),this->comp);
        /* Add to result */
        for(i=0;i<k;i++)   result.push_back(vec[i].first);
        return result;
    }
};

/*
Runtime
6
ms
Beats
27.28%
Analyze Complexity
Memory
17.09
MB
Beats
90.45%

*/