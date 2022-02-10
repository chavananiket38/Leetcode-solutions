class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int size = nums.size();
        vector<int> pre;
        pre.push_back(nums[0]);
        
        for(int i=1; i<size; i++){
            pre.push_back(nums[i] + pre[i-1]);
        }
        
        unordered_map<int, int> mp;
        int cnt = 0;
        for(int i:pre){
            if(i==k)
                cnt++;
            
            if(mp.count(i-k))
                cnt += mp[i-k];
            mp[i]++;
        }
            
        return cnt;
    }
};