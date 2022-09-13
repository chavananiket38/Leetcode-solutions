class Solution {
public:
    unordered_map<char, string> mp = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"},
                                      {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, 
                                      {'8', "tuv"}, {'9', "wxyz"}};
    vector<string> ans;
    
    void helper(int n, int i, string &digits, string curr){
        if(curr.size()==n){
            ans.push_back(curr);
            return;
        }
        
        string temp = mp[digits[i]];
        
        for(int k=0; k<temp.size(); k++){
            helper(n, i+1, digits, curr + temp[k]);
        }
    }
    
    
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        if(n==0)
            return ans;
        
        helper(n, 0, digits, "");
        return ans;
    }
};