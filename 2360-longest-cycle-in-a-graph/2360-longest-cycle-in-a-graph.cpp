class Solution {
public:
    
    int dist = -1;
    
    void dfs(int node, vector<int>& edges, vector<int>& vis, 
             vector<int>& distArray, int len){
        
        if(vis[node]==0){
            vis[node] = 1;
            distArray[node] = len;
            
            if(edges[node]!=-1)
                dfs(edges[node], edges, vis, distArray, len+1);
            
            distArray[node] = -1;
        
        }else{
        
            if(distArray[node]!=-1)
                dist = max(len-distArray[node], dist);
        }
    }
    
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> vis(n, 0), distArray(n, -1);
        
        
        for(int i=0; i<n; i++){
            if(vis[i]==0){
                dfs(i, edges, vis, distArray, 1);
            }
        }
        
        return dist;
    }
};