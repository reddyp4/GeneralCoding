/*
1772. Sort Features by Popularity
Attempted
Medium
Topics
conpanies icon
Companies
Hint
You are given a string array features where features[i] is a single word that represents the name of a feature of the latest product you are working on. You have made a survey where users have reported which features they like. You are given a string array responses, where each responses[i] is a string containing space-separated words.

The popularity of a feature is the number of responses[i] that contain the feature. You want to sort the features in non-increasing order by their popularity. If two features have the same popularity, order them by their original index in features. Notice that one response could contain the same feature multiple times; this feature is only counted once in its popularity.

Return the features in sorted order.

 

Example 1:

Input: features = ["cooler","lock","touch"], responses = ["i like cooler cooler","lock touch cool","locker like touch"]
Output: ["touch","cooler","lock"]
Explanation: appearances("cooler") = 1, appearances("lock") = 1, appearances("touch") = 2. Since "cooler" and "lock" both had 1 appearance, "cooler" comes first because "cooler" came first in the features array.
Example 2:

Input: features = ["a","aa","b","c"], responses = ["a","a aa","a a a a a","b a"]
Output: ["a","aa","b","c"]
 

Constraints:

1 <= features.length <= 104
1 <= features[i].length <= 10
features contains no duplicates.
features[i] consists of lowercase letters.
1 <= responses.length <= 102
1 <= responses[i].length <= 103
responses[i] consists of lowercase letters and spaces.
responses[i] contains no two consecutive spaces.
responses[i] has no leading or trailing spaces.
*/
/*
make map of features, with count of 1
break each response string into individual strings
if string in feature map, update count from 1
insert map[feature,count] into vector pairs, sort in decreasing order
form output vector string
*/

class Solution {
public:
    vector<string> sortFeatures(vector<string>& features, vector<string>& responses) {
        vector<string> result;
        map<string,int> myMap;  //Map of count
        map<string,int> myIndexMap;   //Map of index
        string s;
        for(int i=0;i<features.size();i++)  {
            myMap[features[i]]=1;
            myIndexMap[features[i]]=i;
        }
        /* Split response into individual */
        for(int i=0;i<responses.size();i++) {
            map<string,bool> seen;
            stringstream ss(responses[i]);
            while(getline(ss,s,' '))    
                if(myMap.count(s)>0)
                    if(!seen[s])    {
                        myMap[s]++;
                        seen[s]=true;
                    }
        }
        /* End Split Response */
        /* Print Map */
        //for(auto &key:myMap)
        //    cout<<"key:"<<key.first<<",val:"<<key.second<<endl;
        /* End Print Map */
        /* Turn map into vector */
        vector<pair<string,int>> vec;
        for(auto &key:myMap)    vec.push_back(key);
        /* End Turn map into vector */
        /* Sort vector in decreasing order */
        sort(
            vec.begin(),vec.end(),
            [](pair<string,int>&a,pair<string,int>&b)
            {return a.second>b.second;}
                );
        /* End Sort vector in decreasing order */
        if(vec.size()==1)   return result;
        /* Sort the values in terms of index if count is same */
        int i=0,j;i++;
        //while(i<vec.size()) 
        {
            j=i+1;
            /* Move i until count is same */
            while(vec[j]==vec[i])   j++;
            cout<<"i:"<<i<<",j:"<<j<<endl;
            /* Sort interval */
            sort(vec.begin()+i,vec.begin()+j,[](pair<string,int>&a,pair<string,int>&b)
                {return myIndexMap[a.first]<myIndexMap[b.first];}
                );
        }
        /* End Sort the values in terms of index if count is same */
        /* Form result while looping through vector */
        for(int i=0;i<vec.size();i++)   {
            cout<<vec[i].first<<","<<vec[i].second<<endl;
            result.push_back(vec[i].first);
        }
        return result;
    }
};

/*
Fix second sort
Failing for:
["gm","gueh","pagukeo","mjfmxkpt","nxehzmy","gupciaqa","szpke","m","fafxokiwj","vnolbwofn","rpsjw","vkaouipu",
"xcqshtxzn","rzsntyo","crcevj","oec","gflhav","uvgvrcaat"]

["gyr crcevj oec mjfmxkpt kkecx lzfkaylnlv m rurltdf bbxhe nxehzmy",
"wavzoewzs fcoxpmy vnolbwofn gm xcqshtxzn gm wvod szpke mjfmxkpt uvgvrcaat",
"uvgvrcaat uvgvrcaat sc xft vkaouipu rpsjw gyusm bbwuvi pagukeo cgxoylhuva",
"kv gzkd evlz uvgvrcaat oec mjfmxkpt bazhpl xcqshtxzn xz mjfmxkpt",
"szpke vkaouipu gupciaqa fjvct qykhiiwxhi fvkg aa oec nxehzmy uinreddwh",
"nxehzmy osu hnb urllg uvgvrcaat gm rpsjw muyza nxehzmy gvk",
"gupciaqa meix m mmfkox m tq gupciaqa hhoes pagukeo yoegfotbrs",
"xcqshtxzn sbzvqgxyd wgwyxkxl szpke pkdhgta laqpvfhoh crcevj jkdfwfvxa hrsqbjulr gm",
"sjoitocx szpke qstsf gflhav vnolbwofn qnjaklkw zgzhaseu fafxokiwj vp fafxokiwj"]

output
["uvgvrcaat","szpke","oec","xcqshtxzn","nxehzmy","mjfmxkpt","gm","m","gupciaqa","crcevj","pagukeo","rpsjw","vkaouipu","vnolbwofn",
"gflhav","fafxokiwj","gueh","rzsntyo"]

expected
["szpke","uvgvrcaat","gm","mjfmxkpt","nxehzmy","xcqshtxzn","oec","pagukeo","gupciaqa","m","vnolbwofn","rpsjw","vkaouipu","crcevj",
"fafxokiwj","gflhav","gueh","rzsntyo"]
*/