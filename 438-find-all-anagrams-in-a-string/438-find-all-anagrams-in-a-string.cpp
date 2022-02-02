class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.length()<p.length())return {};
        
        map<char, int> m1;
        map<char, int> m2;
        vector<int> ans;
        
        for(auto ch:p){
            m1[ch]++;
        }
        
        int i = 0;
        int m = p.length(), n = s.length();
        
        for(i=0; i<p.length(); i++){
            m2[s[i]]++;
        }
        
        i = p.length();
        while(i<=s.length()){
            if(m1==m2)ans.push_back(i-m);
            
            m2[s[i]]++;
            if(m2[s[i-m]]==1)m2.erase(s[i-m]);
            else m2[s[i-m]]--;
            i++;
        }
        
        return ans;
    }
};