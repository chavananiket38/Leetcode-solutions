class Solution {
   
public:
   int dp[100001][2][101]; 
    int profit(vector<int> &prices, int day, int curr, int count){
        if(day>=prices.size() or count<=0)return 0;
        
        if(dp[day][curr][count]!=-1)return dp[day][curr][count];
        
        int ideal = profit(prices, day+1, curr, count);
        int ans;
        if(curr){
            ans = -prices[day] + profit(prices, day+1, 0, count);
            
        }else{
            ans = prices[day] + profit(prices, day+1, 1, count-1);
            
        }
        return dp[day][curr][count] = max(ans, ideal);
    }
    
    int maxProfit(int k, vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return profit(prices, 0, 1, k);
    }
};