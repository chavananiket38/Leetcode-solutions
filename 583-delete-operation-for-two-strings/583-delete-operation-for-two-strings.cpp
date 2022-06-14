class Solution {
public:
    
    int helper(string &word1, string &word2, int i, int j, vector<vector<int>> &dp){
        if(i==word1.size() and j==word2.size())
            return 0;
        if(i==word1.size() or j==word2.size())
            return max(word1.size()-i, word2.size()-j);
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        if(word1[i]==word2[j])
            return helper(word1, word2, i+1, j+1, dp);
        dp[i][j] = 1+min(helper(word1, word2, i+1, j, dp), helper(word1, word2, i, j+1, dp));
        return dp[i][j];
    }
    
    int minDistance(string &word1, string &word2) {
        vector<vector<int>> dp(size(word1)+1, vector<int> (size(word2)+1, -1));
        return helper(word1, word2, 0, 0, dp);
    }
};