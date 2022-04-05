class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = INT_MIN;
        
        int start = 0;
        int end = height.size()-1;
        
        while(start<end){
            int area = (end-start)*min(height[start], height[end]);
            ans = max(ans, area);
            
            if(height[start]>height[end])
                end--;
            else 
                start++;
        }
        
        return ans;
    }
};