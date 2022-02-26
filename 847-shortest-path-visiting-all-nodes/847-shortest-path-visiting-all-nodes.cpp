class Solution {
    
    int solve(vector<vector<int>>&graph){
        int n = graph.size();
        int finalMask = (1<<n) - 1;
        
        queue<pair<int, pair<int, int>>> q;
        set<pair<int,int>> vis;
        
        for(int i = 0; i<n; i++){
            int mask = (1<<i);
            q.push({i, {0, mask}});
            vis.insert({i, mask});
        }
        
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            int val = front.first, dist = front.second.first, mask = front.second.second;
            
            for(auto temp:graph[val]){
                int newMask = (mask | 1<<temp);
                
                if(newMask == finalMask)
                    return dist+1;
                else if(vis.count({temp, newMask}))
                    continue;
                
                q.push({temp, {dist+1, newMask}});
                vis.insert({temp, newMask});
            }
        }
        return 0;
    }

public:
    int shortestPathLength(vector<vector<int>>& graph) {
        if(graph.size()==1)return 0;
        
        return solve(graph);
    }
};