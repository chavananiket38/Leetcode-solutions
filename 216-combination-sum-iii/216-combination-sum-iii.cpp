class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    
    void combination3(int curr, int k, int n){
        if(curr>9 || k<=0 || curr>n)
            return;
        if(curr==n && k==1){
            temp.push_back(curr);
            ans.push_back(temp);
            temp.pop_back();
            return;
        }
        
        temp.push_back(curr);
        combination3(curr+1, k-1, n-curr);
        temp.pop_back();
        combination3(curr+1, k, n);
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        ans.clear();
        temp.clear();
        combination3(1, k, n);
        return ans;
    }
};