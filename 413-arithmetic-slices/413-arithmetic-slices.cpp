class Solution {
public:
    unordered_map<int,int> mp;
    int sum = 0;
    
    int solver(vector<int> &nums, int i){
        if(i<2)
            return 0;
        
        if(mp.count(i))return mp[i];
        
        int curr = 0;
        if(nums[i]-nums[i-1]==nums[i-1]-nums[i-2]){
            curr = 1 + solver(nums, i-1);
            sum += curr;
        }else{
            solver(nums, i-1);
        }
        
        return curr;
    }
    
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if(n<=2)return 0;
        sum = 0;
        solver(nums, n-1);
        return sum;
    }
};