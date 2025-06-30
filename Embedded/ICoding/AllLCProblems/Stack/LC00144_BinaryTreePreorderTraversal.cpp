/*
144. Binary Tree Preorder Traversal
Solved
Easy
Topics
conpanies icon
Companies
Given the root of a binary tree, return the preorder traversal of its nodes' values.

 

Example 1:

Input: root = [1,null,2,3]

Output: [1,2,3]

Explanation:



Example 2:

Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]

Output: [1,2,4,5,6,7,3,8,9]

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
Method1: Recursively visit left node, until no child
> visit node
> visit right node
Stack: 
 > Node: push right, push node, visit left

Method2: Stack
> set root as seen, push right, root, left into stack
> pop, 
 > if no left, add to list
> 
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
        bool print=false;
        /* Recursive solution */
        /*
        cout<<"Recursive method"<<endl;
        if(root==NULL)  return vec;
        inorder(root);
        return vec;
        */
        /* Stack soluation */
        TreeNode *node;
        stack<TreeNode*> myStk;
        if(root==NULL)  return vec;
        if(root->left==NULL && root->right==NULL)   {
            vec.push_back(root->val);
            return vec; }
        /*if(root->right!=NULL)   {
            myStk.push(root->right);seen[root->right]=true; 
            cout<<"Push1:"<<(root->right)->val<<endl;    }*/
        myStk.push(root);seen[root]=true;
        if(print)    cout<<"Push2:"<<root->val<<endl;
        /*if(root->left!=NULL)   {
            myStk.push(root->left);seen[root->left]=true;
            cout<<"Push3:"<<(root->left)->val<<endl;   }*/
        while(!myStk.empty())
        {
            //pop, if left -> visit recursively=push-right,node,left 
            node=myStk.top();if(print)    cout<<"Current:"<<node->val<<endl;
            if(node->left!=NULL && !seen[node->left]) {
                /*if(node->right && !seen[node->right]) {
                node=myStk.top();myStk.pop();
                myStk.push(node);
                cout<<"Push7:"<<node->val<<endl;    }
                if(!seen[node]) {
                    myStk.push(node);seen[node]=true;
                    cout<<"Push5:"<<node->val<<endl;    }*/
                myStk.push(node->left);seen[node->left]=true;
                if(print)    cout<<"Push6:"<<(node->left)->val<<endl;
            }
            else if(node->right==NULL)    {
                vec.push_back(node->val);myStk.pop();
                if(print)    cout<<"vec:"<<vec[vec.size()-1]<<endl;
                if(!myStk.empty() && print)   cout<<"new top:"<<(myStk.top())->val<<endl;
            }
            else if(!seen[node->right])   {
                //left=NULL or seen, right is present
                vec.push_back(node->val);myStk.pop();
                if(print)    cout<<"vec:"<<vec[vec.size()-1]<<endl;
                myStk.push(node->right);seen[node->right]=true;
                if(print)    cout<<"Push4:"<<(node->right)->val<<endl;
            }
        }
        if(print)    cout<<endl;
        return vec;
    }
};

/*
Runtime
1
ms
Beats
6.14%
Analyze Complexity
Memory
11.52
MB
Beats
8.98%
*/

/*
Stack solution
Runtime
0
ms
Beats
100.00%
Analyze Complexity
Memory
11.07
MB
Beats

*/