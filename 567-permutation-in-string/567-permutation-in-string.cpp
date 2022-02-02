class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        map<char, int> m1;
        map<char, int> m2;

        int m = s1.length(), n = s2.length();
        
        if(m>n)return false;
        
        for(auto ch:s1)m1[ch]++;
        
        int i = 0;
        for(i = 0; i<m; i++)m2[s2[i]]++;
        i = m;
        
        while(i<=s2.length()){
            if(m1==m2)return true;
            
            m2[s2[i]]++;
            if(m2[s2[i-m]]==1)m2.erase(s2[i-m]);
            else m2[s2[i-m]]--;
            
            i++;
        }
        
        return false;
    }
};