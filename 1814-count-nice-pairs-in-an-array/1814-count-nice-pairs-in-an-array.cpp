class Solution {
public:
    int mod = 1e9 + 7;
    
    int countNicePairs(vector<int>& nums) {
        map<int, long long> mp;
        
        for(int i=0; i<nums.size(); i++){
            string s = to_string(nums[i]);
            reverse(s.begin(), s.end());
            stringstream geek(s);
            int k = 0;
            geek>>k;
            mp[k-nums[i]]++;
        }
        int ans = 0;
        for(auto i:mp)
            if(i.second>1)
                ans += ((i.second*(i.second-1))/2) % mod;
        return ans % mod;
    }
};