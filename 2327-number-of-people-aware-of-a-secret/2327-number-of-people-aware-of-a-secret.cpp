class Solution {
public:
    vector<int> dp;
    int delay, forget, mod=1e9+7;
    
    long helper(int n){
        if(n<=0)
            return 0;
        
        if(dp[n]!=-1)
            return dp[n];
        
        long res = 1;
        for(int i=delay; i<forget; i++){
            if(n-i>=0)
                res = (res + helper(n-i))%mod;
        }
        
        return dp[n] = res;
    }
    
    int peopleAwareOfSecret(int n, int delay, int forget) {
        dp.resize(n+1, -1);
        this->delay = delay;
        this->forget = forget;
        
        return (helper(n)-helper(n-forget)+mod)%mod;
    }
};