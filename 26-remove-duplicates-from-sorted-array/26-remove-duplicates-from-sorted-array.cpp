class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0)return 0;
        int i=0;
        
        for(auto n : nums){
            if(i<1 or n>nums[i-1])
                nums[i++] = n;
        }
        
        return i;
    }
};