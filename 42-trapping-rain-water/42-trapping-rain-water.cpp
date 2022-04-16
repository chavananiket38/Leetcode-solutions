class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        
        vector<int> suffix(n, 0);
        vector<int> prefix(n, 0);
        
        int mx = 0;
        for(int i=0; i<n; i++){
            mx = max(mx, height[i]);
            prefix[i] = mx;
        }
        
        mx = 0;
        for(int i=n-1; i>=0; i--){
            mx = max(mx, height[i]);
            suffix[i] = mx;
        }
        
        int ans = 0;
        for(int i=0; i<n; i++){
            ans += (min(prefix[i], suffix[i])) - height[i];
        }
        return ans;
    }
};