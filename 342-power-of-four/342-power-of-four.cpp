class Solution {
public:
    bool helper(long long i, int k){
        if(i>k)
            return false;
        if(i==k)
            return true;
        
        return helper(4*i, k);
    }
    
    bool isPowerOfFour(int n) {
        if(n==1)
            return true;
        if(n<=0)
            return false;
        return helper(4, n);
    }
    
};

