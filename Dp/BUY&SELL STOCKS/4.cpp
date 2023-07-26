#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices, int n, int k)
{
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));
    //return solve(0,1,prices,2,dp);
    //TABULATION opposite of recrn is it will start from n-1
    //initialisation dp[curr][1][0] = 0 && dp[curr][0][0] = 0;
    for(int i=n-1;i>=0;i--){
        for(int cap = 1;cap<=k;cap++){
            for(int buy = 0;buy<=1;buy++){
                if(buy){
                    dp[i][buy][cap] = max(-prices[i]+dp[i+1][0][cap],dp[i+1][1][cap]);
                }else{
                    dp[i][buy][cap] = max(prices[i]+dp[i+1][1][cap-1],dp[i+1][buy][cap]);
                }
            }
        }
    }
    return dp[0][1][k];
    // Write your code here.
}