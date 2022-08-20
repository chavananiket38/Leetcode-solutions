class Solution {
public:
    int res = 0;
    void dfs(int node, vector<vector<int>> &edge, vector<int> &vis){
        vis[node] = 1;
        
        for(auto i:edge[node]){
            if(vis[i]==0){
                res = res+1;
                dfs(i, edge, vis);
            }
        }
    }
    
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& rest) {
        vector<vector<int>> edge(n);
        vector<int> vis(n, 0);
        for(auto i:edges){
            edge[i[0]].push_back(i[1]);
            edge[i[1]].push_back(i[0]);
        }
        
        for(auto i:rest)
            vis[i] = 1;
        // for(int i=0; i<edge.size(); i++){
        //     cout<<i<<"->";
        //     for(int j=0; j<edge[i].size(); j++)
        //         cout<<edge[i][j]<<" ";
        //     cout<<endl;
        // }
        
        dfs(0, edge, vis);
        return res+1;
    }
    
};