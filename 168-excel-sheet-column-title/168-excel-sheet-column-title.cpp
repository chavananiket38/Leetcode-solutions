class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = "";
        int curr = columnNumber;
        
        while(curr>0){
            curr--;
            
            int mod = curr%26;
            ans += ('A'+mod);
            
            curr/=26;
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};