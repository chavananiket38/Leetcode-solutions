class Solution {
public:
    
    int profit(vector<int> &prices, int day, bool curr, int count,       
               map<tuple<int,bool,int>,int> &dp){
        if(day>=prices.size() or count<=0)return 0;
        
        tuple<int,bool,int> key = make_tuple(day, curr, count);
        
        if(dp.find(key)!=dp.end())return dp[key];
        
        int ideal = profit(prices, day+1, curr, count,dp);
        int buySell = 0;
        if(curr){
            buySell = -prices[day] + profit(prices, day+1, false, count,dp);
        }else{
            buySell = prices[day] + profit(prices, day+1, true, count-1,dp);
        }
        dp[key] = max(ideal, buySell);
        return dp[key];
    }
    
    int maxProfit(vector<int>& prices) {
        map<tuple<int,bool,int>,int> dp;
        return profit(prices, 0, true, 1, dp);
    }
};



// class Solution {
    
//     int solve(vector<int>& prices, int day, bool curr, int count, map<tuple<int, bool, int>, int> &mp){
//         if(day>=prices.size() or count<=0)return 0;
        
//         tuple<int, bool, int> key = make_tuple(day, curr, count);
        
//         if(mp.find(key)!=mp.end())return mp[key];
        
//         int ideal = solve(prices, day+1, curr, count, mp);
        
//         int buySell = 0;
//         if(curr){
//             buySell  = -prices[day] + solve(prices, day+1, false, count, mp);   
//         }else{
//             buySell = prices[day] + solve(prices, day+1, true, count-1, mp);
//         }
        
//         mp[key] = max(ideal, buySell);
//         return mp[key];
//     }
    
// public:
    
//     int maxProfit(vector<int>& prices) {
//         map<tuple<int, bool, int>, int> mp;
//         return solve(prices, 0, true, 1, mp);
//     }
// };