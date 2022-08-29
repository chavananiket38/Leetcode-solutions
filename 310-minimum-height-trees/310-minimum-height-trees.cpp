class Solution {
public:
    
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n); 
        vector<int> indegree(n, 0);
        for(auto i:edges){
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
            
            indegree[i[0]]++;
            indegree[i[1]]++;
        }
        
        vector<int> ans;
        queue<int> q;
        for(int i=0; i<n; i++)
            if(indegree[i]==1)
                q.push(i);
        
        while(!q.empty()){
            int k = q.size();
            ans.clear();
            
            while(k--){
                int node = q.front();
                ans.push_back(node);
                q.pop();
                
                for(auto i:graph[node]){
                    indegree[i]--;
                    if(indegree[i]==1)
                        q.push(i);
                }
            }
        }
        
        if(ans.size()==0)
            return {0};
        return ans;
    }
};