class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(auto i:nums){
            pq.push(i);
        }
        
        while(k--){
            int x = pq.top();
            pq.pop();
            x++;
            pq.push(x);
        }
        
        long long mod = 1e9+7, mult = 1;
        
        while(!pq.empty()){
            mult = (mult*pq.top())%mod;
            pq.pop();
        }
        
        return mult;
    }
};