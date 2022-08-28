class Solution {
public:
    bool checkCycle(int node, vector<vector<int>> &adj, vector<int> &vis,
                    vector<int> &dfsVis) {
        vis[node] = 1;
        dfsVis[node] = 1;
        for (auto it: adj[node]) {
          if (!vis[it]) {
                if (checkCycle(it, adj, vis, dfsVis)) return true;
          } else if (dfsVis[it]) 
                return true;
        }
        dfsVis[node] = 0;
        return false;
    }
    
    void toposort(int node, vector<vector<int>> &edges, vector<int> &vis,
                  stack<int>& st){
        vis[node] = 1;
        
        for(auto i:edges[node]){
            if(vis[i]==0)
                toposort(i, edges, vis, st);
        }
        
        st.push(node);
    }
    
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions,
                                    vector<vector<int>>& colConditions) {
        
        vector<int> vis(k+1, 0), dfsVis(k+1 ,0);
        vector<vector<int>> edges(k+1);
        for(auto i:rowConditions){
            edges[i[0]].push_back(i[1]);
        }
        
        for(int i=1; i<=k; i++){
            if(vis[i]==0)
                if(checkCycle(i, edges, vis, dfsVis))
                    return {};
        }
        stack<int> st;
        fill(vis.begin(), vis.end(), 0);
        for(int i=1; i<=k; i++){
            if(vis[i]==0)
                toposort(i, edges, vis, st);
        }
        vector<vector<int>> vertex(k+1);
        int j=0;
        while(!st.empty()){
            vertex[st.top()].push_back(j);
            j++;
            st.pop();
        }
        
        ////////////////////////////////////////////////////
        
        vector<vector<int>> edge(k+1);
        for(auto i:colConditions){
            edge[i[0]].push_back(i[1]);
        }
        fill(vis.begin(), vis.end(), 0);
        fill(dfsVis.begin(), dfsVis.end(), 0);
        for(int i=1; i<=k; i++){
            if(vis[i]==0)
                if(checkCycle(i, edge, vis, dfsVis))
                    return {};
        }
        fill(vis.begin(), vis.end(), 0);
        for(int i=1; i<=k; i++){
            if(vis[i]==0)
                toposort(i, edge, vis, st);
        }
        
        j=0;
        while(!st.empty()){
            vertex[st.top()].push_back(j);
            j++;
            st.pop();
        }
        
        //////////////////////////////////////
        vector<vector<int>> res(k, vector<int> (k, 0));
        for(int i=1; i<vertex.size(); i++){
            res[vertex[i][0]][vertex[i][1]] = i;
        }
        return res;
    }
};