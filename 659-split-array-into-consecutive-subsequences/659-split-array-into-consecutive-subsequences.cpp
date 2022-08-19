class Solution {
public:
    bool isPossible(vector<int>& nums) {
        map<int,int> mp, subseq;
        
        for(auto i:nums)
            mp[i]++;
        
        for(auto i:nums){
            if(!mp[i]) continue;
            mp[i]--;
            if(subseq[i-1]>0){
                subseq[i-1]--;
                subseq[i]++;
            }else if(mp[i+1] && mp[i+2]){
                mp[i+1]--;
                mp[i+2]--;
                subseq[i+2]++;
            }else return false;
        }
        return true;
    }
};