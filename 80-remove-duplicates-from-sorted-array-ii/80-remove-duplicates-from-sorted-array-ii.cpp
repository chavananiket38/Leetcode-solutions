class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        
        for(auto n: nums){
            if(i<2 or n>nums[i-2])
                nums[i++] = n;
        }
        
        return i;
    }
};