class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        map<int, int> mp{{0, -1}};
        int sum = 0;
        int maxLen = 0;
        
        int size = nums.size();
        for(int i=0; i<size; i++){
            sum += (nums[i]==0 ? -1 : 1);
            if(mp.count(sum))maxLen = max(maxLen, i-mp[sum]);
            else mp[sum] = i;
        }
        
        return maxLen;
    }
};