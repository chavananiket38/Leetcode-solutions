class Solution {
public:
    int mod = 1e9+7;
    map<tuple<int,int,int>,int> mp;
    long long helper(int m, int n, int maxMove, int i, int j){
        if(i<0 or j<0 or i>=m or j>=n)
            return 1;
        if(maxMove==0)
            return 0;
        tuple<int,int,int> t = make_tuple(i,j,maxMove);
        if(mp.count(t))
            return mp[t];
        
        long long a = helper(m, n, maxMove-1, i+1, j);
        long long b = helper(m, n, maxMove-1, i-1, j);
        long long c = helper(m, n, maxMove-1, i, j+1);
        long long d = helper(m, n, maxMove-1, i, j-1);
        
        return mp[t]=(a+b+c+d)%mod;
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        long long ans = helper(m, n, maxMove, startRow, startColumn);
        return ans%mod;
    }
};