class Solution {
public:
    int countVowels(int curr, int total, int n, map<pair<int, int>, int> &mp){
        if(curr==n)
            return 1;
        if(total==0){
            return 0;
        }
        
        pair<int, int> key = {curr, total};
        if(mp.count(key))
            return mp[key];
        
        
        int a = countVowels(curr, total-1, n,mp);
        int b = countVowels(curr+1, total, n, mp);
        
        mp[key] = a+b;
        return mp[key];
    }

    int countVowelStrings(int n) {
        map<pair<int, int>, int> mp;
        
        return countVowels(0, 5, n, mp);
    }
};