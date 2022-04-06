class Solution {
public:
    int threeSumMulti(vector<int>& arr, int X) {
        int n = arr.size(), mod = 1e9+7;
        int ans = 0;
        
        unordered_map<int,int> mp;
        
        for(int i=0; i<n; i++){
            ans = (ans + mp[X - arr[i]])%mod;
            
            for(int j=0; j<i; j++)
                mp[arr[i] + arr[j]]++;
        }
        
        return ans;
    }
};