class Solution {
public:
    
    void canReachBoundary(vector<vector<int>>& grid, int i, int j){
        if(i<0 or j<0 or i>=grid.size() or j>=grid[0].size() or grid[i][j]==0)
            return ;
        
        grid[i][j]=0;
        
        canReachBoundary(grid, i+1, j);
        canReachBoundary(grid, i-1, j); 
        canReachBoundary(grid, i, j+1);
        canReachBoundary(grid, i, j-1); 
    }
    
    
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int ans = 0;
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                
                if((i==0 or j==0 or i==m-1 or j==n-1) && grid[i][j]==1){
                    canReachBoundary(grid, i, j);
                }
            
            }
        }
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1)
                    ans++;
            }
        }
        
        return ans;
    }
};