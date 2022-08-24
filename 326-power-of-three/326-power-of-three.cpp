class Solution {
public:
    bool isPowerOfThree(int n) {
        int k = pow(3, 19);
        return (n>0 && k % n==0);
    }
};