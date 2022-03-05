class Solution {
public:
    int solver(vector<int> &nums, int idx, int size, vector<int> &dp){
        if(idx>=size)
            return 0;
        
        if(dp[idx]!=-1)return dp[idx];
        
        int currVal = nums[idx];
        int currSum = nums[idx];
        int i = idx+1;
        
        while(i<size && nums[i]==currVal){
            currSum += nums[i];
            i++;
        }
        int nextNum = i;
        
        while(i<size && nums[i]==currVal+1){
            i++;
        }
        
        int pickCurr = currSum + solver(nums, i, size, dp);
        int notCurr = solver(nums, nextNum, size, dp);
        
        dp[idx] = max(pickCurr, notCurr);
        return dp[idx];
    }
    
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> dp(20001, -1);
        return solver(nums, 0, nums.size(), dp);
    }
};