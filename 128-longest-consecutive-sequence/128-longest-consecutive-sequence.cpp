class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> st;
        for(auto i:nums)
            st.insert(i);
        
        int n = nums.size();
        int ans = 0;
        
        for(int i=0; i<n; i++){
            if(!st.count(nums[i]-1)){
                int curr = nums[i];
                int temp = 1;
            
                while(st.count(curr+1)){
                    curr++;
                    temp++;
                }
                
                ans = max(temp, ans);
            }
        }
        
        return ans;
    }
};