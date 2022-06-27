class Solution {
public:
    
    bool helper(vector<int>& arr, vector<int>& dp, int curr, int size){
        if(curr<0 or curr>=size or arr[curr]==-1)
            return false;
        if(arr[curr]==0)
            return true;
        
        if(dp[curr]!=-1)
            return dp[curr];
        
        int temp = arr[curr];
        arr[curr] = -1;
        
        bool leftFlag = helper(arr, dp, curr+temp, size);
        bool rightFlag = helper(arr, dp, curr-temp, size);
        
        return dp[curr] = leftFlag or rightFlag;
    }
    
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<int> dp(n+1, -1);
        return helper(arr, dp, start, n);
    }
};