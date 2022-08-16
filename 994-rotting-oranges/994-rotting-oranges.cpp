

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        queue<tuple<int,int,int>> q;
        
        int cntOrg = 0;
        
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++){
                if(grid[i][j]==2)q.push(make_tuple(i, j, 0));
                
                if(grid[i][j]!=0)cntOrg++;
            }
        
        int cnt = 0;
        int ans = 0;
        
        while(!q.empty()){
            int x, y, time;
            tuple<int,int,int> tp = q.front();
            
            tie(x, y, time) = tp;
            
            q.pop();
            
            cnt++;
            ans = max(ans, time);
            
            int dx[] = {1, 0, -1, 0};
            int dy[] = {0, -1, 0, 1};
            
            for(int i=0; i<4; i++){
                int newX = x + dx[i];
                int newY = y + dy[i];
                
                if(newX>=0 and newX<n and newY>=0 and newY<m && grid[newX][newY]==1){
                    grid[newX][newY] = 2;
                    q.push(make_tuple(newX, newY, time+1));
                }
            }
        }
        
        if(cnt==cntOrg)return ans;
        return -1;
    }
};