/*
270. Closest Binary Search Tree Value
Easy
Topics
Companies
Given the root of a binary search tree and a target value, return the value in the BST that is closest to the target. If there are multiple answers, print the smallest.

 

Example 1:


Input: root = [4,2,5,1,3], target = 3.714286
Output: 4
Example 2:

Input: root = [1], target = 4.428571
Output: 1
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
0 <= Node.val <= 109
-109 <= target <= 109
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    private:
         TreeNode* bestnode;
         int printFlag;
    public:
        void checkValue(TreeNode* root, double target) //, TreeNode *bestnode)
        {
            if(root==NULL)  return;
            if(printFlag)
                cout<<root->val<<",diff1:"<<(bestnode->val-target)<<",diff2:"<<abs(target-root->val)<<endl;
            if(abs(bestnode->val-target)==abs(target-root->val))
            {
                cout<<"found a smaller at root"<<endl;
                if(root->val<bestnode->val)
                    bestnode=root;
            }
            else if(abs(bestnode->val-target)>abs(target-root->val))
            {
                cout<<"found a smaller at root"<<endl;
                bestnode=root;
            }
            if(printFlag)
                cout<<"root:"<<root->val<<",bestnode:"<<bestnode->val<<endl;
            if(root->left!=NULL && (root->val>target))  
                checkValue(root->left, target); //, bestnode);
            if(root->right!=NULL && (root->val<target))  
                checkValue(root->right, target); //, bestnode);
        }
        int closestValue(TreeNode* root, double target) {
            double diff=pow(10,10);
            printFlag = 0;
            bestnode=root;
            checkValue(root,target); //,bestnode);
            return bestnode->val;
        }
    };

/*
Runtime
0
ms
Beats
100.00%

Memory
21.37
MB
Beats
16.69%

*/