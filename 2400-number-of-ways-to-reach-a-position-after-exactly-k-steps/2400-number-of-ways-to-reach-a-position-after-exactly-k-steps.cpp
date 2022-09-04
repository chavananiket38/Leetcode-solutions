class Solution {
public:
    vector<vector<int>>dp;
    int mod = 1e9+7;
    
    int helper(int l, int r, int k){
        if(l==r && k==0)
            return 1;
        if(k<=0)
            return 0;
        if(dp[k][l+1000]!=-1)
            return dp[k][l+1000];
        
        return dp[k][l+1000] = (helper(l-1, r, k-1) + helper(l+1, r, k-1)) % mod;
    }
    
    int numberOfWays(int startPos, int endPos, int k) {
        dp.resize(3001, vector<int>(3001, -1));
        return helper(startPos, endPos, k) % mod;    
    }
};