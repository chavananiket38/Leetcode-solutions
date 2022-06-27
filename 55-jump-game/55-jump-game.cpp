class Solution {
public:
    
    bool isPossible(vector<int> &nums, int size, int curr, vector<int> &dp){
        if(curr>=size-1)return true;
        
        
        if(dp[curr]!=-1)return dp[curr];
        
        if(nums[curr]==0)
            return false;
        for(int i=1; i<=nums[curr]; i++){
            if(isPossible(nums,size,curr+i,dp)){
                return dp[curr] = true;
            }
        }
        return dp[curr] = false;
    }
    
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size()+1, -1);
        return isPossible(nums,nums.size(), 0, dp);
    }
};