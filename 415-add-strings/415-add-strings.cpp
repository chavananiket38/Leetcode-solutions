class Solution {
public:
    string addStrings(string num1, string num2) {
        int m = num1.size();
        int n = num2.size();
        vector<int> arr(n+1,0);
        
        if(m>n){
            arr.resize(m+1,0);
        }
        
        int i = m-1, j = n-1;
        while(i>=0 and j>=0){
            if(i>=j){
                int temp = (arr[i+1] + (num1[i]-'0')+(num2[j]-'0'));
                arr[i+1] = temp%10;
                arr[i] = temp/10;
            }else{
                int temp = (arr[j+1] + (num1[i]-'0')+(num2[j]-'0'));
                arr[j+1] = temp%10;
                arr[j] = temp/10;
            }
            i--;
            j--;
        }
        
        if(j!=0 && i>=0){
            while(i>=0){
                int temp = arr[i+1] + (num1[i]-'0');
                arr[i+1] = temp%10;
                arr[i] = temp/10;
                i--;
            }
        }
        if(i!=0 && j>=0){
            while(j>=0){
                int temp = arr[j+1] + (num2[j]-'0');
                arr[j+1] = temp%10;
                arr[j] = temp/10;
                j--;
            }
        }
        
        for(auto i:arr)
            cout<<i<<" ";
        string ans = "";
        for(i=0; i<arr.size(); i++)
            if(arr[i]!=0)
                break;
        
        for(int k=i; k<arr.size(); k++)
            ans += arr[k]+'0';
        
        if(ans=="")
            return "0";
        return ans;
    }
};