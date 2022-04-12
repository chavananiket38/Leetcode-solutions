class Solution {
    
    void helper(vector<vector<int>> &grid){
        int m = grid.size();
        int n = grid[0].size();
        
        int last = grid[m-1][n-1];
        for(int i=m-1; i>=0; i--){
            int temp = grid[i][n-1];

            for(int j=n-2; j>= 0; j--){
                grid[i][j+1] = grid[i][j];
            }
            
            if(i!=(m-1))
                grid[(i+1)%m][0] = temp;
        }

        grid[0][0] = last;
    }
    
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        k = k%(grid.size()*grid[0].size());
        for(int i=0 ;i<k; i++){
            helper(grid);
        }
        
        return grid;
    }
};