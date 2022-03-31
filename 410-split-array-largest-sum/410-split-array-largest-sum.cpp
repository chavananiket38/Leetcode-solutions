class Solution {
public:
    int dp[1001][51];
    int helper(vector<int>& nums, int idx, int m){
        if(idx==0 and m==0)
            return 0;
        
        if(idx==0 or m==0)
            return INT_MAX;
        
        if(dp[idx][m]!=-1)return dp[idx][m];
        int curr = 0;
        int ans = INT_MAX;
        for(int k=idx; k>0; k--){
            curr += nums[k-1];
            ans = min(ans, max(curr, helper(nums, k-1, m-1)));
        }
        
        return dp[idx][m] = ans;
    }
    
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        memset(dp, -1, sizeof dp);
        
        return helper(nums, n, m);
    }
};