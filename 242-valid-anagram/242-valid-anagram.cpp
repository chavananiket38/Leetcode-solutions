class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> mp1;
        map<char, int> mp2;
        for(auto i:t){
            mp1[i]++;
        }
        
        for(auto i:s){
            mp2[i]++;
        }
        
        return (mp1==mp2) ?  true :  false;
    }
};