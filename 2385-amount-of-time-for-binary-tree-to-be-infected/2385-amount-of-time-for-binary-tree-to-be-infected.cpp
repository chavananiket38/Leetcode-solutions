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
    int res = -1, maxEdge = -1;
    
    void getEdges(vector<pair<int,int>> &edges, TreeNode* root, int par){
        if(root==NULL)
            return;
        if(par!=-1)
            edges.push_back({par, root->val});
        
        maxEdge = max(root->val, maxEdge);
        
        getEdges(edges, root->left, root->val);
        getEdges(edges, root->right, root->val);    
    }
    
    void dfs(int node, vector<vector<int>> &edge, vector<int> &vis, int time){
        
        vis[node] = 1;
        res = max(res, time);
        
        for(auto i:edge[node]){
            if(vis[i]==0){
                dfs(i, edge, vis, time+1);
            }
        }
    }
    
    int amountOfTime(TreeNode* root, int start) {
        
        // edges vector for storing edges
        vector<pair<int,int>> edges;
        getEdges(edges, root, -1);
        
        // edge vector for creating Adjacency list.
        vector<vector<int>> edge(maxEdge+1);
        vector<int> vis(maxEdge+1, 0);
        
        for(auto i:edges){
            edge[i.first].push_back(i.second);
            edge[i.second].push_back(i.first);
        }
        
        dfs(start, edge, vis, 0);
        return res;
    }
};