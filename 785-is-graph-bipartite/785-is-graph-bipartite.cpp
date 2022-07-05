class Solution {
public:
    vector<int> vis;
    
    bool isBipartite(vector<vector<int>>& graph, int i){
        queue<int> q;
        q.push(i);
        vis[i]=1;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto k:graph[node]){
                if(vis[k]==-1){
                    vis[k]= 1-vis[node];
                    q.push(k);
                }else if(vis[k]==vis[node]){
                    return false;
                }
            }
            
        }
        
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vis.resize(n, -1);
        
        for(int i=0; i<n; i++){
            if(vis[i]==-1){
                if(!isBipartite(graph, i))
                    return false;
            }
        }
        
        return true;
    }
};