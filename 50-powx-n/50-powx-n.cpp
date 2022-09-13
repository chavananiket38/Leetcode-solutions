class Solution {
public:
    
    double power(double x, int n){
        if(n==0)return 1;
        
        double ans = power(x, n/2);
        
        if(n%2==0) return ans * ans;
        else return n<0 ? ans*ans*1/x : ans * ans * x;
        
    }
    
    double myPow(double x, int n) {
        return power(x,n);
    }
};