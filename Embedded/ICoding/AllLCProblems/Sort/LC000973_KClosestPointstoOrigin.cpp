/*
973. K Closest Points to Origin
Solved
Medium
Topics
conpanies icon
Companies
Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).

The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).

You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).

 

Example 1:


Input: points = [[1,3],[-2,2]], k = 1
Output: [[-2,2]]
Explanation:
The distance between (1, 3) and the origin is sqrt(10).
The distance between (-2, 2) and the origin is sqrt(8).
Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
We only want the closest k = 1 points from the origin, so the answer is just [[-2,2]].
Example 2:

Input: points = [[3,3],[5,-1],[-2,4]], k = 2
Output: [[3,3],[-2,4]]
Explanation: The answer [[-2,4],[3,3]] would also be accepted.
 

Constraints:

1 <= k <= points.length <= 104
-104 <= xi, yi <= 104
*/
/*
M1: Make a map <index,distance>
    Make vector <index,distance>
    Sort vector as per distance
    Retrive the points
M2: LinkedList of sorted distance
*/

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        map<int,float> myMap;       //map of index of points to distance
        vector<vector<int>> answer;
        vector<pair<int,float>> vec;
        float distance;
        bool print=false;
        if(print)   cout<<"points.size:"<<points.size()<<",points[0].size:"<<points[0].size()<<endl;
        for(int i=0;i<points.size();i++)
        {
            distance = sqrt((points[i][0]*points[i][0])+(points[i][1]*points[i][1]));
            if(print)   cout<<"points[i][0]:"<<points[i][0]<<",points[i][1]:"<<points[i][1]<<",distance:"<<distance<<endl;
            myMap[i]=distance;
        }
        //Make the vector from map
        for(auto &key:myMap)    vec.push_back(key);
        //Print vector before
        for(int i=0;i<vec.size();i++)    {
            if(print)   cout<<"Element-"<<i<<":"<<points[vec[i].first][0]<<","<<points[vec[i].first][1]<<endl;
        }
        //Sort the vec in increasing order
        sort(vec.begin(),vec.end(),[](pair<int,float>a,pair<int,float>b){return a.second<b.second;});
        //Add the first k elements into answer
        for(int i=0;i<k;i++)    {
            if(print)   cout<<"Closest-"<<i<<":"<<points[vec[i].first][0]<<","<<points[vec[i].first][1]<<endl;
            answer.push_back(points[vec[i].first]);
        }
        return answer;
    }
};

/*
Runtime
65
ms
Beats
50.11%
Analyze Complexity
Memory
79.34
MB
Beats
30.15%
*/