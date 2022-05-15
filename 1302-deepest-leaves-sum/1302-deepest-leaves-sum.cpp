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
    int deepestLeavesSum(TreeNode* root) {
        if(root==NULL)
            return 0;
        
        queue<TreeNode*> q;
        q.push(root);
        
        vector<int> sum;
        sum.push_back(root->val);
        while(!q.empty()){
            int n = q.size();
            int currSum = 0;
            for(int i=0; i<n; i++){
                TreeNode* temp = q.front();
                q.pop();
                
                if(temp->left!=NULL){
                    q.push(temp->left);
                    currSum += temp->left->val;
                }
                if(temp->right!=NULL){
                    q.push(temp->right);
                    currSum += temp->right->val;
                }
            }
            sum.push_back(currSum);
        }
        
        return sum[sum.size()-2];
    }
};