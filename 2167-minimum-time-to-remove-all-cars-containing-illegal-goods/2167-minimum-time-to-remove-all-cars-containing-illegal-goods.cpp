class Solution {
public:
    int minimumTime(string s) {
        int n = s.size();
        int ans = n;
        vector<int> vec;
        for(auto i:s){
            if(i=='0')vec.push_back(-1);
            else vec.push_back(1);
        }
        
        int mini = 0;
        int sum = 0;
        for(auto it : vec){
            sum += it;
            mini = min(mini, sum);
            if(sum>0)sum = 0;
        }
        
        return ans+mini;
    }
};