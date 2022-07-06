class Solution {
public:
    vector<int> dir = {0, 1, 0, -1, 0};
    int helper(vector<vector<int>>& grid, int i, int j){
        if(i<0 or j<0 or i>=grid.size() or j>=grid[0].size() or grid[i][j]==0)
            return 0;
        
        int res = 0;
        grid[i][j] = 0;
        
        for(int k=0; k<4; k++){
            int x = i+dir[k], y = j+dir[k+1];
            res += helper(grid, x, y);
        }
        
        return res+1;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size(), n = grid[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1){
                    ans = max(ans, helper(grid, i, j));
                }
            }
        }
        
        return ans;
    }
};