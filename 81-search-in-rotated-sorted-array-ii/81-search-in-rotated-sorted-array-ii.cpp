class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int cnt = count(nums.begin(), nums.end(), target);
        
        if(cnt)return true;
        else return false;
    }
};