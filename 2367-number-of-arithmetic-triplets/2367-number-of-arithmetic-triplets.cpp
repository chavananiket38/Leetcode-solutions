class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        map<int,int> mp;
        
        for(auto i:nums)
            mp[i] = 1;
        
        int ans = 0;
        
        for(auto i:nums)
            if(mp[i-diff] && mp[i+diff])
                ans++;
        
        return ans;
    }
};