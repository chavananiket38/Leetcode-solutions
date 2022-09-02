class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        if(n==2) return "11";
        
        string lastStr = countAndSay(n-1);
        int i=0, len = lastStr.size();
        string ans = "";
        
        while(i<len){
            int j = i;
            while(i<len && lastStr[i]==lastStr[j]) i++;
            ans += to_string(i-j) + lastStr[j];
        }
        
        return ans;
    }
};