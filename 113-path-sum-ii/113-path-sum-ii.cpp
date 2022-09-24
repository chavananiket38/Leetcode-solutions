
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    
    void helper(TreeNode* root, int target, int curr){
        if(root==NULL){
            return;
        }
        
        curr += root->val;
        temp.push_back(root->val);
        
        if(root->left==NULL && root->right==NULL && curr==target)
            ans.push_back(temp);
        
        helper(root->left, target, curr);
        helper(root->right, target, curr);
        
        temp.pop_back();
        
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        helper(root, targetSum, 0);
        return ans;
        
    }
};