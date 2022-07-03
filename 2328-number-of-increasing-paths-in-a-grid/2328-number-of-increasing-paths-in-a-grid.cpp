class Solution {
public:
    
    int mod = 1e9+7;
    int dir[5] = {0,1,0,-1,0};
    vector<vector<int>> dp;
    
    int helper(vector<vector<int>>& grid, int i, int j){
        long res=1;
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        for(int k=0; k<4; k++){
            int x = i+dir[k], y = j+dir[k+1];
            if(x>=0 && y>=0 && x<grid.size() && y<grid[0].size() && grid[x][y]>grid[i][j])
                res = (res+helper(grid, x, y))%mod;
        }
        
        return dp[i][j] = res;
    }
    
    int countPaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        dp.resize(m, vector<int> (n, -1));
        
        int ans = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                ans = (ans+helper(grid, i, j))%mod;
            }
        }
        
        return ans%mod;
    }
};