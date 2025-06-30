/*
145. Binary Tree Postorder Traversal
Solved
Easy
Topics
conpanies icon
Companies
Given the root of a binary tree, return the postorder traversal of its nodes' values.

 

Example 1:

Input: root = [1,null,2,3]

Output: [3,2,1]

Explanation:



Example 2:

Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]

Output: [4,6,7,5,2,9,8,3,1]

Explanation:



Example 3:

Input: root = []

Output: []

Example 4:

Input: root = [1]

Output: [1]

 

Constraints:

The number of the nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
 

Follow up: Recursive solution is trivial, could you do it iteratively?
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
public:
    vector<int> vec;
    map<TreeNode*,bool> seen;
    void postorder(TreeNode* root)  {
        if(root->left!=NULL && !seen[root->left])   postorder(root->left);
        if(root->right!=NULL && !seen[root->right])   postorder(root->right);
        seen[root]=true;
        vec.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        if(root==NULL)  return vec;
        postorder(root);
        return vec;
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
11.74
MB
Beats
8.07%
*/