class Solution {
public:
    int mod = 1e9 + 7;
    
    int countNicePairs(vector<int>& nums) {
        
        map<int, int> mp;
        long long ans = 0;   
        
        for(int i=0; i<nums.size(); i++){
            string s = to_string(nums[i]);
            reverse(s.begin(), s.end());
            stringstream geek(s);
            int k = 0;
            geek>>k;
            
            if(mp.count(k-nums[i]))
                ans += (mp[k-nums[i]]) % mod;
            
            mp[k-nums[i]]++;
        }
        
        return ans % mod;
    }
};