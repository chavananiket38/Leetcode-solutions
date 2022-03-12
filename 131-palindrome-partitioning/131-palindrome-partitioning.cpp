class Solution {
public:
    bool isPalindrome(string &s, int start, int i){
        while(start<i){
            if(s[start++]!=s[i--])
                return false;
        }
        
        return true;
    }
    
    void helper(string &s, int start, vector<vector<string>> &result, vector<string> &path){
        int n = s.size();
        if(start==n){
            result.push_back(path);
            return;
        }else{
            for(int i=start; i<n; i++){
                if(isPalindrome(s, start, i)){
                    path.push_back(s.substr(start, i - start + 1));
                    helper(s, i+1, result, path);
                    path.pop_back();
                }
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> path;
        helper(s, 0, result, path);
        return result;
    }
};