class Solution {
public:
    vector<int> vis;
    
    bool isBipartite(vector<vector<int>>& graph, int i, int col){
        vis[i]=col;
            
        for(auto k:graph[i]){
            
            if(vis[k]==-1){
                if(!isBipartite(graph, k, col^1))
                    return false;
                    
            }else if(vis[k]==vis[i]){
                return false;
            }
            
        }
        
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vis.resize(n, -1);
        
        for(int i=0; i<n; i++){
            if(vis[i]==-1){
                if(!isBipartite(graph, i, 1))
                    return false;
            }
        }
        
        return true;
    }
};