class Solution {
public:
    
    bool helper(vector<vector<int>>& grid, int i, int j){
        if(i<0 or j<0 or i>=grid.size() or j>=grid[0].size())
            return false;
        
        if(grid[i][j]==1)
            return true;
        
        grid[i][j] = 1;
        
        bool a = helper(grid, i+1, j);
        bool b = helper(grid, i-1, j);
        bool c = helper(grid, i, j+1);                              
        bool d = helper(grid, i, j-1);
        
        return a && b && c && d;
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int ans = 0;
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==0){
                    
                    ans += helper(grid, i, j)?1:0;
                    
                }
            }
        }
        
        return ans;
    }
};