class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        int n = nums.size();
        if(sum<x)return -1;
        if(sum==x) return n;
        
        int res = 0, start = 0, currentSum = 0, target = sum-x;  
        
        for(int i=0; i<n; i++){
            currentSum += nums[i];
            
            while(currentSum>target)
                currentSum -= nums[start++];
            
            if(currentSum==target)
                res = max(res, i-start+1);
        }
        
        return (res==0) ? -1 : n - res;
    }
};