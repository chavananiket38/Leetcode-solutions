class Solution {
public:
    bool isCycle(int node, vector<vector<int>> &edges, vector<int> &vis, 
                 vector<int> &dfsVis){
        vis[node] = 1;
        dfsVis[node] = 1;
        
        for(auto i:edges[node]){
            if(vis[i]==0){
                if(isCycle(i, edges, vis, dfsVis))
                    return true;
            }else if(dfsVis[i])
                return true;
        }
        
        dfsVis[node] = 0;
        return false;
    }
    
    void toposort(int node, vector<vector<int>> &edges, vector<int> &vis, 
                  stack<int> &st){
        vis[node] = 1;
        
        for(auto i:edges[node]){
            if(vis[i]==0)
                toposort(i, edges, vis, st);
        }
        
        st.push(node);
    }
    
    vector<int> findOrder(int numC, vector<vector<int>>& pre) {
        vector<vector<int>> edges(numC);
        
        for(auto i:pre){
            edges[i[0]].push_back(i[1]);
        }
        
        vector<int> vis(numC, 0), dfsVis(numC, 0);
        for(int i=0; i<numC; i++){
            if(vis[i]==0)
                if(isCycle(i, edges, vis, dfsVis))
                    return {};
        }
        
        stack<int> st;
        fill(vis.begin(), vis.end(), 0);
        for(int i=0; i<numC; i++){
            if(vis[i]==0)
                toposort(i, edges, vis, st);
        }
        
        vector<int> res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};