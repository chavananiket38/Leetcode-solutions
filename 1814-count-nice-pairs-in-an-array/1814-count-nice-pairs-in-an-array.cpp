class Solution {
public:
    int mod = 1e9 + 7;
    
    int reverse(int num){
        long rev=0;
        while(num!=0){
            rev=rev*10 + num%10;
            num/=10;
        }
        return rev;
    }
    
    int countNicePairs(vector<int>& nums) {
        
        map<int, int> mp;
        int ans = 0;   
        
        for(int i=0; i<nums.size(); i++){
            int k = reverse(nums[i]);
            if(mp.count(k-nums[i]))
                ans = (ans%mod) + (mp[k-nums[i]] % mod);
            
            mp[k-nums[i]]++;
        }
        
        return ans % mod;
    }
};