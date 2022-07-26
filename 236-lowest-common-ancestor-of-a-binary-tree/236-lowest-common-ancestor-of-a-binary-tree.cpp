/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* t1, *t2;
    
    TreeNode* helper(TreeNode* root){
        if(root==NULL)
            return NULL;
        
        if(root->val==t1->val or root->val==t2->val)
            return root;
        
        TreeNode *left = helper(root->left);
        TreeNode* right = helper(root->right);
        
        if(left!=NULL && right!=NULL)
            return root;
        
        if(left)
            return left;
        else 
            return right;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        t1 = p;
        t2 = q;
        return helper(root);
    }
};