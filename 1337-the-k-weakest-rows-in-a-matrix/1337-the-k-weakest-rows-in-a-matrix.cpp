class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        
        multimap<int, int> mp;
        for(int i=0; i<n; i++){
            int cnt = count(mat[i].begin(), mat[i].end(), 1);
            mp.insert({cnt, i});
        }
        
        vector<int> res;
        
        for(auto i:mp){
            if(!k--)break;
            res.push_back(i.second);
        }
        
        return res;
    }
};