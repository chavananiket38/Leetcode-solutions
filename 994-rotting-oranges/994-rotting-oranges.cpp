

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int cntOrg = 0;
        queue<tuple<int,int,int>> q;
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==2) q.push(make_tuple(i, j, 0));
                if(grid[i][j]!=0) cntOrg++;
            }
        }
        
        int ans = 0, cnt = 0;
        int dir[] = {1, 0, -1, 0, 1};
        while(!q.empty()){
            int x, y, time;
            tie(x, y, time) = q.front();
            q.pop();
            
            cnt++;
            ans = max(ans, time);
            
            for(int i=0; i<4; i++){
                int newX = x + dir[i];
                int newY = y + dir[i+1];
                
                if(newX>=0 && newX<m && newY>=0 && newY<n && grid[newX][newY]==1){
                    grid[newX][newY] = 2;
                    q.push(make_tuple(newX, newY, time+1));
                }
            }
            
        }
        
        if(cntOrg==cnt) return ans;
        return -1;
    }
};