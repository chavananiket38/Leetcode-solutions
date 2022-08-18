class Solution {
    static bool cmp(pair<int,int> &a, pair<int,int> &b){
        return a.first>b.first;
    }
    
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> mp;
        int n = arr.size();
        for(auto i:arr)
            mp[i]++;
        
        vector<pair<int,int>> v;
        for(auto i:mp){
            v.push_back({i.second, i.first});
        }
        sort(v.begin(), v.end(), cmp);
        
        int cnt = 0, total = n;
        for(auto i:v){
            if(total<=n/2)
                return cnt;
            if(total>n/2){
                total -= i.first;
                cnt++;
            }
        }
        
        return cnt;
    }
};