class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        if(nums.size()<=3)return ans;
        
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++){
            
                int newTarget = target - nums[i];
                
                for(int j=i+1; j<n; j++){
                    
                        int newTarget2 = newTarget - nums[j];
                        
                        int lo = j+1;
                        int hi = nums.size()-1;
                    
                        while(lo<hi){
                            
                            int two_sum = nums[lo]+nums[hi];
                            
                            if(two_sum<newTarget2) lo++;
                            else if(two_sum>newTarget2)hi--;
                            else{
                                vector<int> v;
                                v.push_back(nums[i]);
                                v.push_back(nums[j]);
                                v.push_back(nums[lo]);
                                v.push_back(nums[hi]);
                                ans.push_back(v);
                                
                                while(lo<hi && nums[lo]==nums[lo+1])lo++;
                                while(lo<hi && nums[hi]==nums[hi-1])hi--;
                                
                                lo++;
                                hi--;
                            }
                            
                        }
                    while(j+1<n && nums[j]==nums[j+1])++j;
                }
            while(i+1<n && nums[i]==nums[i+1])++i;
        }
        
        return ans;
    }
};