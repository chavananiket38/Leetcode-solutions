class Solution {
public:
    unordered_map<int, int> mp;
    bool helper(vector<int>& stones, int n, int curr, int k,  map<pair<int,int>, bool> &dp){
        if(mp[curr]==false || curr>stones[n-1])
            return false;
        if(curr==stones[n-1])
            return true;
        
        if(dp.find({curr, k})!=dp.end())
            return dp[{curr,k}];
        
        bool isPossible;
        if(curr==0)
            isPossible = helper(stones, n, curr+1, 1, dp);
        else{
            if(k-1>0)
                isPossible = helper(stones, n, curr+(k-1), k-1, dp);
            if(isPossible)return true;
            isPossible = helper(stones, n, curr+k, k, dp);
            if(isPossible)return true;
            isPossible = helper(stones, n, curr+(k+1), k+1, dp);
            if(isPossible)return true;
        }
        
        return dp[{curr,k}] = isPossible;
    }
    
    bool canCross(vector<int>& stones) {
        
        int n = stones.size();
        for(auto i:stones)
            mp[i] = true;
            
        map<pair<int,int>, bool> dp;
        return helper(stones, n, 0, 1, dp);
    }
};