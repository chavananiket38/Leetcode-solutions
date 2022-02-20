class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end()); 
        nums.push_back(INT_MAX);
        int count;
        if(nums.size() == 1){
            count = *nums.begin();
        }else{
        for(int i = 0 ; i < nums.size(); i++){
           if(nums[i] != nums[i+1]){
                count = nums[i];
               break;
           } else{
               i++;
           }
         }
        }
        return count;
    }
};