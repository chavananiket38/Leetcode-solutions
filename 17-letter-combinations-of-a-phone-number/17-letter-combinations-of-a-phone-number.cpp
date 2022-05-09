class Solution {
public:
    
    void combination(string &digits, int start, unordered_map<char, string> &mp, 
                     vector<string> &ans, string combi){
        if(combi.size()==digits.size()){
            ans.push_back(combi);
            return;
        }
        
        string curr = mp[digits[start]];
        
        for(int i=0; i<curr.size(); i++){
            combination(digits, start+1, mp, ans, combi+curr[i]);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string combi = "";
        
        if(digits == "")
            return ans;
        
        unordered_map<char, string> mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        
        combination(digits, 0, mp, ans, combi);
        return ans;
    }
};