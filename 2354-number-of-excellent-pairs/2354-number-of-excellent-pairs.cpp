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
        set<int> st;
        for(auto i:nums)
            st.insert(i);
        vector<int> v;
        for(auto i:st)
            v.push_back(i);
        
        vector<int> arr;
        
        for(auto i:v){
            int k = i;
            int cnt = 0;
            while(k){
                k = k&(k-1);
                cnt++;
            }
            arr.push_back(cnt);
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