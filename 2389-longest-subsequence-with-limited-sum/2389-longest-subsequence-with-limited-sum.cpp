class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        vector<int> pre(nums.size());
        pre[0] = nums[0];
            
        for(int i=1; i<pre.size(); i++)
            pre[i] = pre[i-1] + nums[i];
        
        vector<int> ans;
        for(auto i:queries){
            int it = upper_bound(pre.begin(), pre.end(), i) - pre.begin();
            ans.push_back(it);
        }
        
        return ans;
    }
};