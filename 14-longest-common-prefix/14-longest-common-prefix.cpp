class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if(n==0)
            return "";
        
        sort(strs.begin(), strs.end());
        string ans = "";
        string lo = strs[0];
        string hi = strs[n-1];
        
        int k = lo.size();
        for(int i=0; i<k; i++){
            if(lo[i]==hi[i])
                ans += lo[i];
            else break;
        }
        
        
        return ans;
    }
};