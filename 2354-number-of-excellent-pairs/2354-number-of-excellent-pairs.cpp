class Solution {
public:
    long long countExcellentPairs(vector<int>& nums, int k) {
        unordered_set<int> st(nums.begin(), nums.end());
        vector<int> cnt(30,0);
        
        for(auto i:st)
            ++cnt[__builtin_popcount(i)];
        long long res = 0;
        
        for(int i=1; i<30; i++)
            for(int j=1; j<30; j++)
                if(i+j>=k)
                    res += cnt[i]*cnt[j];
        
        return res;
    }
};