/*
244. Shortest Word Distance II
Attempted
Medium
Topics
conpanies icon
Companies
Design a data structure that will be initialized with a string array, and then it should answer queries of the shortest distance between two different strings from the array.

Implement the WordDistance class:

WordDistance(String[] wordsDict) initializes the object with the strings array wordsDict.
int shortest(String word1, String word2) returns the shortest distance between word1 and word2 in the array wordsDict.
 

Example 1:

Input
["WordDistance", "shortest", "shortest"]
[[["practice", "makes", "perfect", "coding", "makes"]], ["coding", "practice"], ["makes", "coding"]]
Output
[null, 3, 1]

Explanation
WordDistance wordDistance = new WordDistance(["practice", "makes", "perfect", "coding", "makes"]);
wordDistance.shortest("coding", "practice"); // return 3
wordDistance.shortest("makes", "coding");    // return 1
 

Constraints:

1 <= wordsDict.length <= 3 * 104
1 <= wordsDict[i].length <= 10
wordsDict[i] consists of lowercase English letters.
word1 and word2 are in wordsDict.
word1 != word2
At most 5000 calls will be made to shortest.
*/
#include <iostream>
#include <unordered_map>
#include <utility>

class WordDistance {
public:
    //matrix of distances, includes the string1 and string2
    std::map<std::pair<std::string,std::string>,int> distance;

    WordDistance(vector<string>& wordsDict) {
        //cout<<wordsDict.size()<<endl;
        for(int i=0;i<wordsDict.size();i++)
        {
            for(int j=i+1;j<wordsDict.size();j++) 
            {
                //First string
                string str1=wordsDict[i];
                //Second string
                string str2=wordsDict[j];
                //cout<<"str1:"<<str1<<",str2:"<<str2<<endl;
                if(str1<str2)
                {
                    //Check if string already present, if present, put the min otherwise assign
                    if(distance.count({str1,str2})>0)  //[str1,str2] element present
                    {
                        distance[{str1,str2}]=min(distance[{str1,str2}],j-i);
                    }
                    else
                    {
                        distance[{str1,str2}]=j-i;
                    }
                }
                else
                {
                    //Check if string already present, if present, put the min otherwise assign
                    if(distance.count({str2,str1})>0)  //[str1,str2] element present
                    {
                        distance[{str2,str1}]=min(distance[{str2,str1}],j-i);
                    }
                    else
                    {
                        distance[{str2,str1}]=j-i;
                    }
                }
            }
        }
    }
    
    int shortest(string word1, string word2) {
        if(word1<word2)   return distance[{word1,word2}];
        return distance[{word2,word1}];
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */
