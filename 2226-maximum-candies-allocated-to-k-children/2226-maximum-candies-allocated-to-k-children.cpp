class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long sum = 0;
        for(auto i:candies)
            sum+=i;
        if(k>sum)
            return 0;
        
        long long ans = 0;
        int start = 0, end = sum/k;
        end++;
        while(start<end){
            long long mid = (start+end)/2;
            
            if(mid==0)return 0;
            long long cnt = 0;
            for(auto i:candies){
                cnt += (i/mid);
            }
            
            if(cnt>=k){
                ans = max(ans, mid);
                start = mid+1;
            }else
                end = mid;
        }
        
        return ans;
    }
};