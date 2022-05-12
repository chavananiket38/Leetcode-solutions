class Solution {
public:
    
    void permutation(int curr, int n, set<vector<int>> &ans, vector<int>& nums){
        if(curr==n){
            ans.insert(nums);
            return;
        }
        
        permutation(curr+1, n, ans, nums);
        
        for(int j=curr+1; j<n; j++){
            swap(nums[j], nums[curr]);
            permutation(curr+1, n, ans, nums);
            swap(nums[j], nums[curr]);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> ans;
        vector<vector<int>> res;
        
        int n = nums.size();
        permutation(0, n, ans, nums);
        
        for(auto i:ans)
            res.push_back(i);
        
        return res;
    }
};