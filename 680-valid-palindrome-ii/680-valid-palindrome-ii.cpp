class Solution {
public:
    bool validPalindrome(string s) {
        int start = 0;
        int end = s.size()-1;
        
        bool ans1 = true;
        int pass = 0;
        while(start<=end){
            if(s[start]!=s[end] && pass==0){
                start++;
                pass++;
            }else if(s[start]!=s[end] && pass==1){
                ans1 = false;
                break;
            }else{
                start++;
                end--;
            }
        }
        
        start = 0;
        end = s.size()-1;
        pass = 0;
        bool ans2 = true;
        while(start<=end){
            if(s[start]!=s[end] && pass==0){
                end--;
                pass++;
            }else if(s[start]!=s[end] && pass==1){
                ans2 = false;
                break;
            }else{
                start++;
                end--;
            }
        }
        
        
        return ans1 || ans2;
    }
};