class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        int size = nums[0].size();
        
        for(int i=0; i<queries.size(); i++){
            
            int maxIdx = queries[i][0];
            int trim = queries[i][1];
            
            vector<pair<string,int>> mp;
            for(int i=0; i<nums.size(); i++){
                mp.push_back({nums[i].substr(size-trim), i});
            }
            
            sort(mp.begin(), mp.end());
            ans.push_back(mp[maxIdx-1].second);
            
        }
        
        return ans;
    }
    
    // vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
    //     vector<int> res;
    //     int n = nums.size();
    //     for(auto &q:queries) {
    //         vector<pair<string,int>> pq;
    //         for(int i=0;i<n; i++) {
    //             pq.push_back({(nums[i].substr(nums[i].size()-q[1])), i});
    //         }
    //         sort(pq.begin(), pq.end());
    //         res.push_back(pq[q[0]-1].second);
    //     }
    //     return res;
    // }
};