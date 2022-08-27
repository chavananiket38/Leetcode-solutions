class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int n = nums.size();
        int minx = INT_MAX;
        int total = 0;
        for(auto i:nums){
            total += i;
            minx = min(total, minx);
        }
        if(minx>0)
            return 1;
        return minx*-1 + 1;
    }
};