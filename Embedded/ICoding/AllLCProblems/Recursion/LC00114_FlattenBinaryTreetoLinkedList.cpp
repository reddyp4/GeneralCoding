/*
114. Flatten Binary Tree to Linked List
Solved
Medium
Topics
conpanies icon
Companies
Hint
Given the root of a binary tree, flatten the tree into a "linked list":

The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.
 

Example 1:


Input: root = [1,2,5,3,4,null,6]
Output: [1,null,2,null,3,null,4,null,5,null,6]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [0]
Output: [0]
 

Constraints:

The number of nodes in the tree is in the range [0, 2000].
-100 <= Node.val <= 100
 

Follow up: Can you flatten the tree in-place (with O(1) extra space)?
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
 /* Preorder reversal and make linked list
 Recursive: Push root to stack, if left move left recursively,  */
class Solution {
public:
    stack<TreeNode*> myStk;
    TreeNode *newRoot,*node;
    vector<TreeNode*> vec;
    map<TreeNode*,bool> seen;
    void preorder(TreeNode* root)
    {
        if(root && !seen[root]) vec.push_back(root);
        seen[root]=true;
        if(root->left && !seen[root->left]) preorder(root->left);
        if(root->right && !seen[root->right]) preorder(root->right);
    }
    void flatten(TreeNode* root) {
        TreeNode* node;
        if(root==NULL)  return;
        //cout<<"Check1"<<endl;
        if(root->left==NULL && root->right==NULL)    return;
        //cout<<"Alg"<<endl;
        /* In recursive, go left recursively until null, then process main and go right recursively */
        preorder(root);
        /* update vec */
        //cout<<"vector:size:"<<vec.size()<<endl;
        for(int i=0;i<vec.size()-1;i++) {
            //cout<<vec[i]->val<<","<<endl;
            vec[i]->right=vec[i+1];
            vec[i]->left=NULL;
        }
        vec[vec.size()-1]->right=NULL;
        vec[vec.size()-1]->left=NULL;
        return;
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
21.15
MB
Beats
7.81%
*/