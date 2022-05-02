class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int lo = 0;
        int hi = nums.size()-1;
        
        while(lo<hi){
            if(nums[lo]%2==1 && nums[hi]%2==0){
                swap(nums[lo], nums[hi]);
                lo++;
                hi--;
            }else if(nums[lo]%2==0 && nums[hi]%2==1){
                hi--;
                lo++;
            }else if(nums[lo]%2==0 && nums[hi]%2==0){
                lo++;
            }else if(nums[lo]%2==1 && nums[hi]%2==1){
                hi--;
            }
        }
        
        return nums;
    }
};