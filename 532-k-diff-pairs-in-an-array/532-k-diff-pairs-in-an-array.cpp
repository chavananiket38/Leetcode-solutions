class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        map<int ,int> mp;
        set<pair<int, int>> st;
        
        int size = nums.size();
        for(int i=0; i<size; i++){
                if(mp.count(nums[i]+k))
                    st.insert({nums[i], nums[i]+k});
                if(mp.count(nums[i]-k))
                     st.insert({nums[i]-k, nums[i]});
                mp[nums[i]]++;
        }
        
        return st.size();
    }
};