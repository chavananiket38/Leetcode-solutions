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
    TreeNode* reverseOddLevels(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        int idx = 0;
        
        while(!q.empty()){
            int n = q.size();
            vector<int> tp;
            
            for(int i=0; i<n; i++){
                TreeNode *node = q.front();
                q.pop();
                tp.push_back(node->val);
                
                if(node->left)
                    q.push(node->left);
                
                if(node->right)
                    q.push(node->right);
            }
            if(idx%2)
                reverse(tp.begin(), tp.end());
            ans.push_back(tp);
            idx++;
        }
        
        q.push(root);
        idx = 0;
        while(!q.empty()){
            int n = q.size();
            vector<int> tp = ans[idx];
            
            for(int i=0; i<n; i++){
                TreeNode *node = q.front();
                q.pop();
                node->val = tp[i];
                
                if(node->left)
                    q.push(node->left);
                
                if(node->right)
                    q.push(node->right);
            }
            idx++;
        }
        
        return root;
    }
};