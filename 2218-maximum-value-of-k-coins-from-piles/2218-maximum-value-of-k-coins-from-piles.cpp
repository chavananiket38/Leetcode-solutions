class Solution {
public:
    int helper(int idx, int k, vector<vector<int>>& piles, vector<vector<int>> &dp){
        if(idx==piles.size() || k==0)
            return 0;
        
        if(dp[idx][k]!=-1)return dp[idx][k]; 
        
        int best = helper(idx+1, k, piles, dp);
        int sum = 0;
        
        for(int i=0; i<min((int)piles[idx].size(), k); i++){
            sum += piles[idx][i];
            best = max(best,sum + helper(idx+1, k - (i+1), piles, dp));
        }
        
        return dp[idx][k] = best;
    }
    
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        vector<vector<int>> dp(piles.size(), vector<int> (k+1, -1));
        return helper(0, k, piles, dp);
    }
};