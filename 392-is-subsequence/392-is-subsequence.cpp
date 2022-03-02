class Solution {
public:
    bool subseq(string &s, string &t, int i, int j, int size1, int size2, 
               vector<vector<int>> &dp){
        
        if(i==size1)return true;
        if(j==size2)return false;
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        if(s[i]==t[j]){
            dp[i][j] = subseq(s, t, i+1, j+1, size1, size2, dp);
            return dp[i][j];
        }
        
        dp[i][j] = subseq(s, t, i, j+1, size1, size2, dp);
        return dp[i][j];
    }
    
    bool isSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n, vector<int>(m+1, -1));
        
        return subseq(s, t, 0, 0, n, m, dp);
    }
};