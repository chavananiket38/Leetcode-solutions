class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size()-1;
        int j = num2.size()-1;
        
        int carry = 0;
        string res = "";
        
        while(i>=0 || j>=0 || carry){
            long temp = 0;
            if(i>=0){temp += num1[i]-'0'; i--;}
            if(j>=0){temp += num2[j]-'0';j--;}
            
            temp += carry;
            carry = temp/10;
            res += (temp%10)+'0';
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};