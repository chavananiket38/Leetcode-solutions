class Solution {
public:
    long long dp[100001][4][3];
    
    long long helper(int idx, int end, string &s, int total, int lastElement){
        if(total==0)return 1;
        if(idx>=end)return 0;
        
        if(dp[idx][total][lastElement+1]!=-1)
            return dp[idx][total][lastElement+1];
        
        long taken = 0;
        if((s[idx]-'0')!=lastElement)
            taken = helper(idx+1, end, s, total-1, s[idx]-'0');
        
        long notTaken = helper(idx+1, end, s, total, lastElement);
        
        return dp[idx][total][lastElement+1] = taken+notTaken;
    }
    
    long long numberOfWays(string s) {
        int n = s.size();
        memset(dp, -1, sizeof dp);
        return helper(0, n, s, 3, -1);
    }
};