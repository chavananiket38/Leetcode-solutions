class Solution {
public:
    int removePalindromeSub(string s) {
        int n = s.size();
        if(n==0)
            return 0;
        
        int i=0, j=n-1;
        bool isPalindrome = true;
        while(i<j){
            if(s[i++]!=s[j--])
                isPalindrome = false;
        }
        
        if(isPalindrome==true)
            return 1;
        else return 2;
    }
};