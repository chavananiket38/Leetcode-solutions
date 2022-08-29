class Solution {
public:
    bool isCycle(int node, vector<vector<int>> &graph, vector<int> &vis, 
                 vector<int> &dfsVis){
        vis[node] = 1;
        dfsVis[node] = 1;
        
        for(auto i:graph[node]){
            if(vis[i]==0){
                if(isCycle(i, graph, vis, dfsVis))
                    return true;
            }else if(dfsVis[i])
                return true;
        }
        
        dfsVis[node] = 0;
        return false;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, 0), dfsVis(n, 0);
        
        for(int i=0; i<n; i++){
            if(vis[i]==0)
                if(isCycle(i, graph, vis, dfsVis))
                    continue;
        }
        
        vector<int> ans;
        for(int i=0; i<n; i++)
            if(dfsVis[i]==0)
                ans.push_back(i);
        
        return ans;
    }
};