class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int del = 0;
        int n = nums.size();
        
        for(int i=0; i<n-1; i++){
            int newIndex = i - del;
            if(nums[i]==nums[i+1] && newIndex%2==0)
                del++;
        }
        
        if((n-del)%2==1)del++;
        
        return del;
    }
};