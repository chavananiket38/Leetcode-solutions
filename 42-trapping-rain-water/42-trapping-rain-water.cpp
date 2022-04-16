class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        
        int lo = 0, hi = n-1;
        int maxLeft = 0, maxRight = 0;
        int res = 0;
        
        while(lo<=hi){
            
            if(height[lo]<=height[hi]){
                
                if(height[lo]>maxLeft)
                    maxLeft = height[lo];
                else 
                    res += maxLeft - height[lo];
                
                lo++;
            }else{
                if(height[hi]>maxRight) 
                    maxRight = height[hi];
                else 
                    res += maxRight - height[hi];
                
                hi--;
            }
        }
        
        return res;
    }
};