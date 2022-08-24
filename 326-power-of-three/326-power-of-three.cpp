class Solution {
public:
    bool helper(long long i, int k){
        if(i>k)
            return false;
        if(i==k)
            return true;
        
        return helper(3*i, k);
    }
    
    bool isPowerOfThree(int n) {
        if(n==1)
            return true;
        if(n<=0)
            return false;
        return helper(3, n);
    }
};