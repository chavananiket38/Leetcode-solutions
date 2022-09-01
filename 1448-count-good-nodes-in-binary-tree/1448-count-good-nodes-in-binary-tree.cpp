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
    int ans = 0;
    
    void helper(TreeNode* root, map<int,int> &mp){
        if(root==NULL)
            return;
        auto it = mp.upper_bound(root->val);
        
        if(it==mp.end())
            ans++;
        
        mp[root->val]++;
        
        helper(root->left, mp);
        
        
        helper(root->right, mp);
        
        
        if(mp[root->val]>1)
            mp[root->val]--;
        else mp.erase(root->val);
    }
    
    int goodNodes(TreeNode* root) {
        map<int, int> mp;
        helper(root, mp);
        return ans;
    }
};