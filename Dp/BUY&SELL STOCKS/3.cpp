#include <bits/stdc++.h> 
int solve(int curr,int buy,vector<int>&prices,int cap){
    //base condn;
    int n =prices.size();
    if(curr==n||cap==0) return 0;
    //recursion calls
    if(buy){
        return max(-prices[curr]+solve(curr+1,0,prices,cap),solve(curr+1,1,prices,cap));
    }else{
        return max(prices[curr]+solve(curr+1,1,prices,cap-1),solve(curr+1,0,prices,cap));
    }
}
int maxProfit(vector<int>& prices, int n)
{
    return solve(0,1,prices,2);
}

//MEMOIZATION
#include <bits/stdc++.h> 
int solve(int curr,int buy,vector<int>&prices,int cap,vector<vector<vector<int>>> &dp){
    //base condn;
    int n =prices.size();
    if(curr==n||cap==0) return 0;
    if(dp[curr][buy][cap]!=-1) return dp[curr][buy][cap];
    //recursion calls
    if(buy){
        return dp[curr][buy][cap]=max(-prices[curr]+solve(curr+1,0,prices,cap,dp),solve(curr+1,1,prices,cap,dp));
    }else{
        return dp[curr][buy][cap]=max(prices[curr]+solve(curr+1,1,prices,cap-1,dp),solve(curr+1,0,prices,cap,dp));
    }
}
int maxProfit(vector<int>& prices, int n)
{
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
    return solve(0,1,prices,2,dp);
}

//TABULATION
#include <bits/stdc++.h> 
int maxProfit(vector<int>& prices, int n)
{
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
    //return solve(0,1,prices,2,dp);
    //TABULATION opposite of recrn is it will start from n-1
    //initialisation dp[curr][1][0] = 0 && dp[curr][0][0] = 0;
    for(int i=n-1;i>=0;i--){
        for(int cap = 1;cap<=2;cap++){
            for(int buy = 0;buy<=1;buy++){
                if(buy){
                    dp[i][buy][cap] = max(-prices[i]+dp[i+1][0][cap],dp[i+1][1][cap]);
                }else{
                    dp[i][buy][cap] = max(prices[i]+dp[i+1][1][cap-1],dp[i+1][buy][cap]);
                }
            }
        }
    }
    return dp[0][1][2];
}