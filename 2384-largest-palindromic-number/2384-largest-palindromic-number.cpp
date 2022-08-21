class Solution {
public:
    
    string largestPalindromic(string num) {
        int mp[10] = {0};
        
        for(auto i:num)
            mp[i-'0']++;
        
        int oddMax = -1;
        string temp = "";
        
        for(int i=9; i>=0; i--){
            if(temp.empty() && i==0) continue;
            
            while(mp[i]>1){
                temp.push_back(i+'0');
                mp[i] -= 2;
            }
            if(mp[i]==1 && oddMax==-1) oddMax = i;
        }
        
        if(temp.empty() && oddMax==-1)
            return "0";
        string res = "";
        res += temp ;
        if(oddMax!=-1){
            temp.push_back(oddMax+'0');
        }
        res+= string(temp.rbegin(), temp.rend());
        return res;
    }
};