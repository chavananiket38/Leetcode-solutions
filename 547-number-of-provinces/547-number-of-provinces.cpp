class Solution {
public:
    
    void dfs(vector<vector<int>> &list, int edge, vector<int> &vis){
        vis[edge] = 0;
        
        for(auto i:list[edge])
            if(vis[i]==-1)
                dfs(list, i, vis);
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<vector<int>> list(isConnected.size());
        
        for(int i=0; i<isConnected.size(); i++){
            for(int j=0; j<isConnected[0].size(); j++){
                if(i!=j && isConnected[i][j]==1)
                    list[i].push_back(j);
            }
        }
        vector<int> vis(list.size(), -1);
        int res = 0;
        for(int i=0; i<list.size(); i++){
            if(vis[i]==-1){
                res++;
                dfs(list, i, vis);
            }  
        }
        
        return res;
    }
};