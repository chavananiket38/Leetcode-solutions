class Solution {
public:
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        vector<vector<int>> graph(n);
        for(int i=0; i<edges.size(); i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<int> vis(n, 0);
        vis[source]=1;
        queue<int> q;
        q.push(source);
        
        while(!q.empty()){
            int node = q.front();
            if(node==destination)
                return true;
            q.pop();
            for(auto k:graph[node]){
                if(vis[k]==0){
                    q.push(k);
                    vis[k]=1;
                }
            }
        }
        return false;
    }
};