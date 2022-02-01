class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int maxDif = -1;
        int size = nums.size();
        for(int i=0; i<size; i++){
            for(int j=i+1; j<size; j++){
                if(nums[j]>nums[i]){
                    maxDif = max(maxDif, nums[j]-nums[i]);
                }
            }
        }
        
        return maxDif;
    }
};