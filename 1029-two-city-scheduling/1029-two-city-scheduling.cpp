class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        multimap<int, vector<int>> mp;
        
        for(auto i:costs){
            mp.insert({i[0]-i[1], i});
        }
        
        int ans = 0;
        int j = 0;
        int mid = costs.size()/2;
        
        for(auto it=mp.begin(); it!=mp.end(); it++, j++){
            if(j<mid){
                ans+=it->second[0];
            }else{
                ans+=it->second[1];
            }
        }
        
        return ans;
    }
};