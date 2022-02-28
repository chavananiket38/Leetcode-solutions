class Solution {
public:
    vector<string> summaryRanges(vector<int> nums) {
        
        string s = "";
        
        int n = nums.size();
        vector<string> v;
        if(n==0)return v;
        
        nums.push_back(INT_MAX);
        n = nums.size();
        
        
        int a = nums[0];
        
        for(int i=0; i<n-1; i++){
            if(nums[i]==nums[i+1]-1)continue;
            else{
                if(a==nums[i]){
                    v.push_back(to_string(a));
                    a = nums[i+1];
                    continue;
                }
                string str = to_string(a) + "->" + to_string(nums[i]);
                v.push_back(str);
                a = nums[i+1];
            }
        }
        
        return v;
    }
};