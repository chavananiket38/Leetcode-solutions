class Solution {
public:
    string getSmallestString(int n, int k) {
        string s (n, 'a');
        k -= n;
        
        int lastChar = n-1;
        while(k){
            if(k>=25){
                s[lastChar] = 'z';
                k -= 25;
                lastChar--;
            }else{
                s[lastChar] = 'a' + k;
                k -= k;
                lastChar--;
            }
        }
        
        return s;
    }
};