// class Solution {
// public:
//     bool search(vector<int>& nums, int target) {
//         int start = 0;
//         int end = nums.size()-1;
        
//         while(start<=end){
            
//             int mid = start + (end-start)/2;
            
//             if(nums[mid]==target)
//                 return true;
            
//             if(nums[start]==nums[mid] && nums[end]==target){
//                 start++;
//                 end--;
//             }
//             else if(nums[start]<=nums[mid]){
//                 if(target<nums[mid] && target>=nums[start])
//                     end = mid-1;
//                 else
//                     start = mid+1;
//             }else{
//                 if(target>nums[mid] && nums[end]>=target)
//                     start = mid+1;
//                 else 
//                     end = mid-1;
//             }
//         }
        
//         return false;
//     }
// };


class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        
        while(l <= r)
        {
            int mid = l + (r-l) / 2;
            if (nums[mid] == target)
                return true;
			// with duplicates we can have this contdition, just update left & right
            if((nums[l] == nums[mid]) && (nums[r] == nums[mid]))
            {
                l++;
                r--;
            }
			// first half
			// first half is in order
            else if(nums[l] <= nums[mid])
            {
				// target is in first  half
                if((nums[l] <= target) && (nums[mid] > target))
                    r = mid - 1;
                else
                    l = mid + 1;
            }
			// second half
			// second half is order
			// target is in second half
            else
            {
                if((nums[mid] < target) && (nums[r]>= target))
                    l = mid + 1;
                else
                    r = mid - 1;
            }
        }
        return false;
    }
	// for github repository link go to my profile.
};