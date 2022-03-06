class Solution {
public:
    int countOrders(int n) {
        long ans  = 1;
        int mod = 1e9 + 7;
        int n1 = n;
        
        while(n1>0){
            ans *= n1;
            n1--;
            ans %= mod;
        }
        
        int x = 1;
        
        while((2*n-x)>0){
            ans *= (2*n - x);
            x += 2;
            ans  %= mod;
        }
        
        return ans;
    }
};