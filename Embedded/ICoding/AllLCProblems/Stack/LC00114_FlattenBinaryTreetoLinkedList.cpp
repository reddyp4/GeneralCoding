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
/* stack: push left to stack */
class Solution {
public:
    void flatten(TreeNode* root) {
        map<TreeNode*,bool> seen;
        vector<TreeNode*> vec;
        TreeNode* node;
        stack<TreeNode*> myStk;
        if(root==NULL)  return;
        if(root->left==NULL && root->right==NULL)    return;
        myStk.push(root);seen[root]=true;
        vec.push_back(root);
        while(!myStk.empty())
        {
            node=myStk.top();
            //cout<<node->val<<","<<endl;
            if(node->left && !seen[node->left]) {
                vec.push_back(node->left);seen[node->left]=true;
                myStk.push(node->left);
            }
            else if(node->right && !seen[node->right])  {
                vec.push_back(node->right);seen[node->right]=true;
                myStk.push(node->right);
            }
            else
            {
                myStk.pop();
            }
        }
        for(int i=0;i<vec.size()-1;i++)
        {
            vec[i]->left=NULL;
            vec[i]->right=vec[i+1];
        }
        vec[vec.size()-1]->left=NULL;
        vec[vec.size()-1]->right=NULL;
    }
};

/*
Runtime
4
ms
Beats
1.89%
Analyze Complexity
Memory
18.22
MB
Beats
7.81%
*/