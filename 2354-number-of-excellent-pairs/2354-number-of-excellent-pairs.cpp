class Solution {
public:
    
    int search(vector<int> &arr, int r, int x){
        int l = 0;
        int res = -1;
        
        while(l<=r){
            int mid = (l+r)/2;
            
            if(arr[mid]>=x){
                res = mid;
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        return res;
    }
    
    long long countExcellentPairs(vector<int>& nums, int k) {
        set<int> st(nums.begin(), nums.end());
        vector<int> arr;
        
        for(auto i:st){
            arr.push_back(__builtin_popcount(i));
        }
        
        sort(arr.begin(), arr.end());
        long long ans = 0;
        
        for(int i=0; i<arr.size(); i++){
            if(arr[i]>=k)
                ans+= i*2+1;
            else{
                int idx = search(arr, i, k-arr[i]);
                
                if(idx!=-1)
                    ans += (i-idx)*2+1;
            }
        }
        
        return ans;
    }
};