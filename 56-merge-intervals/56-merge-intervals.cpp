class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intr) {
        vector<vector<int>> merged;
        if(intr.size()==0)
            return merged;
        
        sort(intr.begin(), intr.end());        
        vector<int> temp = intr[0];
        
        for(auto it:intr){
            if(it[0]<=temp[1]){
                temp[1] = max(it[1], temp[1]);
            }else{
                merged.push_back(temp);
                temp = it;
            }
        }
        
        merged.push_back(temp);
        return merged;
    }
};