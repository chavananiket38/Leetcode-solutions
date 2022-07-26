class Solution {
public:
    string multiply(string num1, string num2) {
        int n = num1.size();
        int m = num2.size();
        vector<int> arr(n+m, 0);
        
        int i = m-1;
        while(i>=0){
            int a = num2[i]-'0';
            int carry = 0;
            for(int j=n-1; j>=0; j--){
                int b = num1[j]-'0';
                int temp = a*b + arr[i+j+1] + carry;
                
                arr[i+j+1] = temp%10;
                carry = temp/10;
            }
            arr[i] += carry;
            i--;
        }
        
        string ans = "";
        
        for(i=0; i<n+m; i++){
            if(arr[i]!=0)
                break;
        }
        for(int j=i; j<n+m; j++)
            ans += arr[j]+'0';
        if(ans=="")
            return "0";
        return ans;
    }
};