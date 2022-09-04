class Solution {
public:
    vector<int> bit;
    
    void setBit(int n, bool b){
        for(int i=0; i<32; i++){
            if(n&1 && b)bit[31-i]++;
            if(n&1 && !b)bit[31-i]--;
            
            n>>=1;
        }
    }
    
    bool check(){
        for(auto i:bit)
            if(i>1)
                return false;
        return true;
    }
    
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        bit.resize(32,0);
        
        
        int left = 0, res = 1;
        setBit(nums[0], 1);
        for(int i=1; i<n; i++){
            setBit(nums[i], 1);
            
            if(check())res++;
            else{
                setBit(nums[left], 0);
                left++;
            }
            
        }
        return res;
    }
};