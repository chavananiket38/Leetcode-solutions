class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int totalLand = 0;
        int sideLand = 0;
        
        int m = grid.size();
        int n = grid[0].size();
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                
                if(grid[i][j]==1){
                    totalLand += 1;
                    
                    if(i!=0 && grid[i-1][j]==1) sideLand++;
                    if(j!=0 && grid[i][j-1]==1) sideLand++;
                }
                
            }
        }
        
        return totalLand*4 - sideLand*2;
    }
};