class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        set<pair<int,int>> st;
        
        int size = nums.size();
        
        if(k==0){
            map<int,int> mp;
            int ans = 0;
            for(auto i:nums){
                mp[i]++;
            }
            
            for(auto i:mp)
                if(i.second>1)ans++;
            
            return ans;
        }
        
        for(int i=0; i<size; i++){
            int start = i;
            int end = size-1;
            
            int num = nums[i]+k;
            
            while(start<=end){
                int mid = (start+end)/2;
                if(nums[mid]==num){
                    st.insert({nums[i], num});
                }
                
                if(nums[mid]<num){
                    start++;
                }else{
                    end--;
                }
            }
        }
        return st.size();
    }
};