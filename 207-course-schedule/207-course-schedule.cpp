class Solution {
public:
    
    vector<int> vis;
    vector<int> currVis;
    bool isCycle(vector<vector<int>> &graph, int i, vector<int> &vis, vector<int> &currVis){
        vis[i]=1;
        currVis[i]=1;
        
        
        for(auto k:graph[i]){
            if(vis[k]==0){
                if(isCycle(graph, k, vis, currVis))
                    return true;
            }else if(currVis[k]==1)
                return true;
        }
        
        currVis[i]=0;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        int n = pre.size();
        
        vector<vector<int>> graph(numCourses);
        
        for(int i=0; i<n; i++){
            graph[pre[i][1]].push_back(pre[i][0]);
        }
        
        
        vis.resize(numCourses, 0);
        currVis.resize(numCourses, 0);
        
        for(int i=0; i<numCourses; i++){
            if(vis[i]==0)
                if(isCycle(graph, i, vis, currVis))
                    return false;
        }
        
        return true;
    }
};













//         for(int i=0; i<numCourses; i++){
//             cout<<i<<"-->";
//             for(auto k:graph[i])
//                 cout<<k<<" ";
//             cout<<endl;
//         }