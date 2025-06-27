/*
94. Binary Tree Inorder Traversal
Solved
Easy
Topics
conpanies icon
Companies
Given the root of a binary tree, return the inorder traversal of its nodes' values.

 

Example 1:

Input: root = [1,null,2,3]

Output: [1,3,2]

Explanation:



Example 2:

Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]

Output: [4,2,6,5,7,1,3,9,8]

Explanation:



Example 3:

Input: root = []

Output: []

Example 4:

Input: root = [1]

Output: [1]

 

Constraints:

The number of nodes in the tree is in the range [0, 100].
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
/*
> Recursively visit left node, until no child
> visit node
> visit right node
Stack: 
 > Node: push right, push node, visit left
*/ 
class Solution {
public:
    vector<int> vec;
    map<TreeNode*,int> seen;
    void inorder(TreeNode* root)
    {
        seen[root]=true;
        if(root->left && !seen[root->left])  inorder(root->left);
        vec.push_back(root->val);
        if(root->right && !seen[root->right]) inorder(root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        /* Recursive solution */
        if(root==NULL)  return vec;
        inorder(root);
        return vec;
        /* Stack soluation */
        /*
        vector<int> vec;TreeNode *node;
        stack<TreeNode*> myStk;
        map<TreeNode*,int> seen;
        if(root==NULL)  return vec;
        if(root->left==NULL && root->right==NULL)   {
            vec.push_back(root->val);
            return vec; }
        if(root->right!=NULL)   myStk.push(root->right);
        myStk.push(root->right);
        if(root->left!=NULL)   myStk.push(root->left);
        while(!myStk.empty())
        {
            //pop, if left -> visit recursively=push-right,node,left 
            cout<<"Top:"<<(myStk.top())->val<<endl;
            if((myStk.top())->left!=NULL && seen[myStk.top()]==0) {
                //push right, node, left to stack
                node=myStk.top();myStk.pop();
                if(node->right) {
                    myStk.push(node->right);cout<<"Push:"<<(node->right)->val<<endl;
                    seen[node->right]=1;    }
                myStk.push(node);cout<<"Push:"<<node->val<<endl;seen[node]=1;
                if(node->left) {
                    myStk.push(node->left);cout<<"Push:"<<(node->left)->val<<endl;
                    seen[node->left]=1;  }
                }
            //no left
            else    {vec.push_back((myStk.top())->val);seen[myStk.top()]=2;
                myStk.pop();    }
        }
        return vec;*/
    }
};

/*
Recursion:
Runtime
4
ms
Beats
0.57%
Analyze Complexity
Memory
11.56
MB
Beats
9.43%
*/