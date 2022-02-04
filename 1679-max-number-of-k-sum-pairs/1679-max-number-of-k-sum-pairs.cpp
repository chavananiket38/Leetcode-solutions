class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        map<int, int> mp;
        
        int cnt = 0;
        
        for(int i=0; i<nums.size(); i++){
           
            if(mp.count(k-nums[i])){
                
                if(mp[k-nums[i]]<=1)mp.erase(k-nums[i]);
                else if(mp[k-nums[i]]>1) mp[k-nums[i]]--;
                
                
                cnt++;
            }else{
                mp[nums[i]]++;
            }
        }
        
        return cnt;
    }
};