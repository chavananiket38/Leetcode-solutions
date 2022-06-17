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
    int Monitored = -1, Need_camera = 0, has_camera = 1;
    int cnt = 0;
    
    int helper(TreeNode* root){
        if(root==NULL)
            return Monitored;
        
        int left = helper(root->left);
        int right = helper(root->right);
        
        if(left == Need_camera || right == Need_camera){
            cnt++;
            return has_camera;
        }
        
        else if(left == has_camera || right == has_camera)
            return Monitored;
        
        return Need_camera;
    }
    
    int minCameraCover(TreeNode* root) {
        int res = helper(root);
        if(res == Need_camera)return cnt+1;
        
        return cnt;
    }
};