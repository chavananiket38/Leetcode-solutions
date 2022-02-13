class Solution {
    vector<vector<int>> ans;
public:
    
    void helper(int start, vector<int> &nums, int end, vector<int> &temp){
        if(start>=end ){
            ans.push_back(temp);
            return;
        }
        
        temp.push_back(nums[start]);
        helper(start+1, nums, end, temp);
        temp.pop_back();
        helper(start+1, nums, end, temp);
        
        return;
        
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        ans.clear();
        vector<int> temp;
        helper(0, nums, nums.size(), temp);
        return ans;
    }
};