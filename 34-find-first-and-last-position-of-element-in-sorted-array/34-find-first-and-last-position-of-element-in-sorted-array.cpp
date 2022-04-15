class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int start = 0;
        int end = nums.size()-1;
        
        int first = -1;
        int last = -1;
        while(start<=end){
            int mid = start + (end-start)/2;
            
            if(target==nums[mid]){
                end = mid-1;
                first = mid;
            }else if(nums[mid]>target)
                 end = mid-1;
            else start = mid+1;
        }
        
        start = 0;
        end = nums.size()-1;
        while(start<=end){
            int mid = start + (end-start)/2;
            
            if(target==nums[mid]){
                start = mid+1;
                last = mid;
            }else if(nums[mid]>target)
                 end = mid-1;
            else start = mid+1;
        }
        
        return {first, last};
    }
};