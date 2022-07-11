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
    
    void helper(TreeNode* root, vector<int> &v, int curr){
        if(root==NULL)
            return;
        if(curr>=v.size())
            v.push_back(root->val);
        helper(root->right, v, curr+1);
        helper(root->left, v, curr+1);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> v;
        
        helper(root, v, 0);
        return v;
    }
};