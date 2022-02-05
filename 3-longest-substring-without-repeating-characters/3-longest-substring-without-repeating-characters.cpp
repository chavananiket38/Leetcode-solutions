class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n<=1)return n;
        
        unordered_map<char, int> mp;
        int ans = 1, j = 0;
        
        for(int i=0; i<s.size(); i++){
            
            if(mp.count(s[i])){
                j = max(mp[s[i]]+1, j);
                mp[s[i]] = i;
            }else{
                mp[s[i]] = i;
            }
            ans = max(ans, i - j + 1);
        }
        return ans;
    }
};