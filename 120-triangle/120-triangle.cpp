class Solution {
public:
    
    int minPath(vector<vector<int>>& triangle, int row, int col, vector<vector<int>> &dp){
        if(row==triangle.size())
            return 0;
        
        if(dp[row][col]!=-1)
            return dp[row][col];
        
        dp[row][col] = triangle[row][col] + min(minPath(triangle, row+1, col, dp),minPath(triangle, row+1, col+1, dp));
        return dp[row][col];
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();
        int col = row;
        vector<vector<int>> dp(row, vector<int> (col, -1));
        
        int ans = INT_MAX;
        ans = minPath(triangle, 0, 0, dp);
        
        return ans;
    }
};