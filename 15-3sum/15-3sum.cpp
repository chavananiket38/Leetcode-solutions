class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size()<=2)return ans;
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<nums.size()-2; i++){
           if(i==0 || (i>0 && nums[i] != nums[i-1])) {
                int lo = i+1;
                int hi = nums.size()-1;
               while(lo<hi){
                    
                    if(nums[lo]+nums[hi]==(-nums[i])){
                        vector<int> v;
                        v.push_back(nums[i]);
                        v.push_back(nums[lo]);
                        v.push_back(nums[hi]);
                        ans.push_back(v);

                        while(lo<hi && nums[lo]==nums[lo+1])lo++;
                        while(lo<hi && nums[hi]==nums[hi-1])hi--;
                        
                        lo++;
                        hi--;
                    }

                    else if(nums[lo]+nums[hi]>(-nums[i]))hi--;
                    else lo++;
                }
            }
        }
        
        return ans;
    }
    
};