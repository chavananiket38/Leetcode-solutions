class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        int res = 0, curr = 0;
        for(int i=0, j=0; j<n; j++){
            while(st.count(nums[j])){
                st.erase(nums[i]);
                curr -= nums[i++];
            }
            
            st.insert(nums[j]);
            curr += nums[j];
            res = max(res, curr);
        }
        
        return res;
    }
};