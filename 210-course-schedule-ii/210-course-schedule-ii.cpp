class Solution {
public:
    
    bool toposort(int node, vector<vector<int>> &edges, vector<int> &vis, 
                  stack<int> &st, vector<int> &dfsVis){
        vis[node] = 1;
        dfsVis[node] = 1;
        
        for(auto i:edges[node]){
            if(vis[i]==0){
                if(toposort(i, edges, vis, st, dfsVis))
                    return true;
            }else if(dfsVis[i])
                return true;
        }
        
        dfsVis[node] = 0;
        st.push(node);
        return false;
    }
    
    vector<int> findOrder(int numC, vector<vector<int>>& pre) {
        vector<vector<int>> edges(numC);
        for(auto i:pre){
            edges[i[0]].push_back(i[1]);
        }
        
        vector<int> vis(numC, 0), dfsVis(numC, 0);
        stack<int> st;
        
        for(int i=0; i<numC; i++){
            if(vis[i]==0)
                if(toposort(i, edges, vis, st, dfsVis))
                    return {};
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