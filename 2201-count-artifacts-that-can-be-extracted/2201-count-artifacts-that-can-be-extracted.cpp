class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        vector<vector<int>> hash(n, vector<int> (n, 0));
        
        for(auto it:dig){
            hash[it[0]][it[1]] = 1;
        }
        
        int ans = 0;
        for(auto it:artifacts){
            int x1 = it[0];
            int y1 = it[1];
            int x2 = it[2];
            int y2 = it[3];
            bool b = true;
            for(int i=x1; i<=x2; i++){
                for(int j=y1; j<=y2; j++){
                    if(hash[i][j]==0){
                        b = false;
                        break;
                    }
                }
            }
            ans += b;
        }
        
        return ans;
    }
};