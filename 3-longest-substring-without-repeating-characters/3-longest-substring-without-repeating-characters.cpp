class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n<=1)return n;
        
        unordered_map<char, int> mp;
        int ans = 0, j = 0, i = 0;
        
        for(int j=0; j<s.size(); ){
            mp[s[j]]++;
            if(mp[s[j]]==1)ans = max(ans, (j-i)+1);
            else{
                while(s[i]!=s[j]){
                    mp[s[i++]]--;
                }
                
                mp[s[i++]]--;
            }
            j++;
        }
        return ans;
    }
};