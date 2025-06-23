/*
48. Rotate Image
Medium
Topics
conpanies icon
Companies
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

 

Example 1:


Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]
Example 2:


Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
 

Constraints:

n == matrix.length == matrix[i].length
1 <= n <= 20
-1000 <= matrix[i][j] <= 1000
*/
/*
rotation by 90:
<1,1> to <1,3>
<3,1> to <1,1>

<m,n> to ?? equidistant from center, and rotate by 90
if even, 1,2,3,4 -> use 2.5?
if odd, 1,2,3 -> use 2
for every index, m,n, vector c-m,c-n rotated by 90 = 
a+bj * j = aj-b and added +c,+c i.e. -b+c, a+c 
too complicated

simpler: 
go from row 1 to len/2 if even, len/2+1 
elements: s-2*(i-1)
row m-1, col:[(m)-1:(s-m+1)-1]
col s-m+1: row:[m-1:(s-m+1)-1]
row (s-m+1)-1: col:[(m)-1:(s-m+1)-1]
col m-1:
*/

class Solution {
public:
    void printMatrix(vector<vector<int>>& matrix) {
        int size=matrix.size();
        //cout<<"size:"<<size<<endl;
    }

    void rotate(vector<vector<int>>& matrix) {
        //printMatrix(matrix);
        int s=matrix.size();
        int toprow, rightcol, bottomrow, leftcol;
        for(int m=0;m<(int)(s/2);m++)
        {
            //elements
            //int n=0;
            for(int n=0;n<(s-1-2*m);n++)
            {
                //cout<<"m:"<<m<<",n:"<<n<<endl;
                toprow = m;
                rightcol = (s-m)-1;
                bottomrow = (s-m)-1;
                leftcol = m;
                //cout<<"toprow:"<<toprow<<",rightcol:"<<rightcol<<",bottomrow:"<<bottomrow<<",leftcol:"<<leftcol<<endl;
                int temp = matrix[toprow][m+n];
                /* Top Row, left to right */
                /* Right column, bottom to top */
                /* Bottom Row, right to left */
                /* Left Column, top to bottom */
                //cout<<"[1]:"<<matrix[toprow][m+n]<<",[2]:"<<matrix[bottomrow-n][leftcol];
                //cout<<",[3]:"<<matrix[bottomrow][rightcol-n]<<",[4]:"<<matrix[m+n][rightcol]<<endl;
                matrix[toprow][m+n]=matrix[bottomrow-n][leftcol];
                matrix[bottomrow-n][leftcol]=matrix[bottomrow][rightcol-n];
                matrix[bottomrow][rightcol-n]=matrix[m+n][rightcol];
                matrix[m+n][rightcol]=temp;
            }
        }
    }
};

/*
Runtime
0
ms
Beats
100.00%
Analyze Complexity
Memory
10.16
MB
Beats
68.58%

*/