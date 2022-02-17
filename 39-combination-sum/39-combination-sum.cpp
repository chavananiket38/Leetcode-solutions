class Solution {
    vector<int> temp;
    vector<vector<int>> ans;
public:
    
    void helper(int size, int idx, vector<int>& candidates, int target){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        
        if(idx>=size)return;
        
        if(candidates[idx]<=target){
            
            temp.push_back(candidates[idx]);
            helper(size, idx, candidates, target-candidates[idx]);
            temp.pop_back();
            
        }
        
        helper(size, idx+1, candidates, target);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        int size = candidates.size();
        ans.clear();
        
        helper(size, 0, candidates, target);
        return ans;
        
    }
};