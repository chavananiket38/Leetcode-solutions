class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> vec(256, -1);
        
        int ans = 0, curr = -1;
        
        for(int i=0; i<s.size(); i++){
            int k = vec[s[i]];
            if(k>curr)
                curr = k;
            vec[s[i]] = i;
            ans = max(ans, i-curr);
        }
        
        return ans;
    }
};