class Solution {
public:
    int helper(int n, vector<int> &dp){
        if(n<=0)
            return 0;
        if(n==1)
            return 1;
        if(dp[n]!=-1)
            return dp[n];
        
        dp[n] = helper(n-1,dp)%mod+helper(n-2,dp)%mod;
        return dp[n];
    }
    int mod = 1e9+7;
    int countHousePlacements(int n) {
        vector<int> dp(n+3, -1);
        long long ans = helper(n+2, dp)%mod;
        ans = ((ans%mod)*(ans%mod))%mod;
        return ans%mod;
    }
};