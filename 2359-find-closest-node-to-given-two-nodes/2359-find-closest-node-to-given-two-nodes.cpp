class Solution {
public:
    
    void dfs(vector<int> &edges, int i, vector<int> &arr, int dist){
        if(i==-1 or arr[i]!=-1)
            return;
        
        arr[i] = dist;
        dfs(edges, edges[i], arr, dist+1);
    }
    
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        vector<int> one(edges.size(), -1), two(edges.size(), -1);
        
        dfs(edges, node1, one, 0);
        dfs(edges, node2, two, 0);
        
        int res = -1, dist = INT_MAX;
        for(int i=0; i<edges.size(); i++){
            if(min(one[i], two[i])>=0 && max(one[i],two[i])<dist){
                dist = max(one[i], two[i]);
                res = i;
            }
        }
        
        return res;
    }
};