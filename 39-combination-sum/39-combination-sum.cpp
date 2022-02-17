class Solution {
    vector<vector<int>> ans;
public:
    
    void helper(int size, int idx, vector<int>& candidates, vector<int> temp, int target){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        
        if(idx>=size)return;
        
        if(candidates[idx]<=target){
            temp.push_back(candidates[idx]);
            int a = candidates[idx];
            helper(size, idx, candidates, temp, target-a);
            temp.pop_back();
        }
        
        helper(size, idx+1, candidates, temp,target);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int size = candidates.size();
        ans.clear();
        vector<int> temp;
        helper(size, 0, candidates, temp, target);
        return ans;
    }
};