class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long int n = nums.size();
        unordered_map<int,long long> mp;
        long long ans = 0;
        
        for(int i=0; i<n; i++){
            mp[nums[i]-i]++;
        }
        
        for(auto i:mp)
		    if(i.second>1)
			    ans += (i.second*(i.second-1))/2;
        
        long long total = (n*(n-1))/2;
        return total - ans;
    }
};