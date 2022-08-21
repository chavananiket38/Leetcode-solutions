class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> mp;
        for(auto i:s)
            mp[i]++;
        
        
        int hasOdd = -1;
        int ans = 0;
        for(auto i:mp){
            if(i.second%2){
                hasOdd = 1;
                ans += i.second-1;
            }
            else ans += i.second;
        }
        
        if(hasOdd==-1)
            return ans;
        return ans+1;
    }
};