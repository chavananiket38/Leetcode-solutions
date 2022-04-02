class Solution {
public:
    bool validPalindrome(string s) {
        
        int start = 0, end = s.size()-1;
        
        int cnt1 = 0;
        while(start<=end){
            if(s[start]==s[end]){
                start++;
                end--;
            }else{
                start++;
                cnt1++;;
            }
        }
        
        start = 0, end = s.size()-1;
        int cnt2 = 0;
        while(start<=end){
            if(s[start]==s[end]){
                start++;
                end--;
            }else{
                end--;
                cnt2++;
            }
        }
        
        
        if(cnt1==0 || cnt2==0 || cnt1==1 || cnt2==1) return true;
        else return false;
    }
};