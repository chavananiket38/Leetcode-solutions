class Solution {
public:
    map<pair<int,int>,int> mp;
    
    int helper(int i, int j, int m, int n){
        if(i==m && j==n)
            return 1;
        if(i>m or j>n)
            return 0;
        
        if(mp.count({i,j}))
            return mp[{i,j}];
        
        return mp[{i,j}] = helper(i+1, j, m, n) + helper(i, j+1, m, n);
    }
    
    int uniquePaths(int m, int n) {
        return helper(1, 1, m, n);
    }
};