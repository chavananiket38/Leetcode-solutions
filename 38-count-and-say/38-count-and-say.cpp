class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        for(int k=2; k<=n; k++){
            string lastStr = ans;
            int i=0, len = lastStr.size();
            ans = "";
            while(i<len){
                int j = i;
                while(i<len && lastStr[i]==lastStr[j]) i++;
                ans += to_string(i-j) + lastStr[j];
            }
        }
        return ans;
    }
};