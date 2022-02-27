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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL)return 0;
        
        int ans = 1;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        
        
        while(!q.empty()){
            int size = q.size();
            
            int start = q.front().second;
            int end = q.back().second;
        
            ans = max(ans, end - start + 1);
            
            for(int i=0; i<size; i++){
                pair<TreeNode*, int> node = q.front();
                
                int idx = node.second - start;
                q.pop();
                
                if(node.first->left != NULL)
                    q.push({node.first->left, 2ll * idx + 1});
                
                if(node.first->right != NULL)
                    q.push({node.first->right, 2ll * idx + 2});
            }
        }
        
        return ans;
    }
};