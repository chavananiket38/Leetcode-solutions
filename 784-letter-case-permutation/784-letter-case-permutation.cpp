class Solution {
    set<string> ans;
public:
    
    void helper(string &s, int i, int end){
        if(i>=end){
            ans.insert(s);
            return;
        }
        
        if(s[i]>64 && s[i]<91){
            char a = s[i]+32;
            s[i] = a;
        }else if(s[i]>96 && s[i]<123){
            char a = s[i]-32;
            s[i] = a;
        }
        
        helper(s, i+1, end);
        
        if(s[i]>64 && s[i]<91){
            char a = s[i]+32;
            s[i] = a;
        }else if(s[i]>96 && s[i]<123){
            char a = s[i]-32;
            s[i] = a;
        }
        
        helper(s, i+1, end);
        return ;
    }
    
    vector<string> letterCasePermutation(string s) {
        vector<string> ansArr;
        helper(s, 0, s.size());
        
        for(auto s:ans)ansArr.push_back(s);
        return ansArr;
    }
};