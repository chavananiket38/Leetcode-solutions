class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& inter) {
        sort(inter.begin(), inter.end());
        
        int a = inter[0][0];
        int b = inter[0][1];
        
        int ans = 1;
        int size = inter.size();
        
        for(int i=0; i<size; i++){
            
            if(inter[i][0]>a && inter[i][1]>b){
                ans++;
            }
            
            if(inter[i][1]>b){
                a = inter[i][0];
                b = inter[i][1];
            }
        }
        
        return ans;
    }
};