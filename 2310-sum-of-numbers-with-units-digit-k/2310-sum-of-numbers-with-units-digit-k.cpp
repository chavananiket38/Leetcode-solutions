class Solution {
public:
    vector<int> dp;
    
    int helper(int sum, int k){
        if(sum==0)return 0;
        if(sum<0)return INT_MAX;
        
        if(dp[sum]!=-1)
            return dp[sum];
        long long ans = INT_MAX;
        
        for(int i=max(k, 1); i<=sum; i++){
            if(i%10==k){
                ans = min(ans, (long long)1+helper(sum-i, k));
            }
        }
        
        return dp[sum] = ans;
    }
    
    int minimumNumbers(int num, int k) {
        dp.resize(num+1, -1);
        int ans = helper(num, k);
        if(ans==INT_MAX)return -1;
        else return ans;
    }
};