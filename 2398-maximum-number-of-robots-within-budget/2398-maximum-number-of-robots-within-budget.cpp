class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        int j = 0, i = 0, multi = 0;
        
        long long currbgt = 0;
        long long sum = 0;
        int res = 0;
        map<int, int> mp;
        
        while(i<chargeTimes.size()){
            mp[-chargeTimes[i]]++;
            sum += runningCosts[i];
            i++;
            multi = i - j;
            currbgt = -mp.begin()->first + multi*sum;
            
            if(currbgt<=budget) res = max(res, multi);
            
            while(currbgt > budget){
                mp[-chargeTimes[j]]--;
                if(mp[-chargeTimes[j]]==0) mp.erase(-chargeTimes[j]);
                sum -= runningCosts[j];
                j++;
                multi = i-j;
                currbgt = -mp.begin()->first + multi*sum;
            }
        }
        
        return res;
    }
};