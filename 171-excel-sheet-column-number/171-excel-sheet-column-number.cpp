class Solution {
public:
    int titleToNumber(string Title) {
        
        int ans = 0;
        
        for(auto i:Title){
            
            int num = i - 64;
            ans = ans*26 + num;
            
        }
        
        return ans;
    }
};