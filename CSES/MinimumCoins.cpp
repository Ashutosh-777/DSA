#include <bits/stdc++.h>
using namespace std;
int solve(int n,int i,int a[],int sum,vector<vector<int>> &dp){
    if(i==n&&sum==0) return 0;
    if(i==n&&sum!=0) return 1e9;
    int temp2 = 1e9;
    int mod =1e9+7;
    if(dp[i][sum]!=-1) return dp[i][sum];
    if(a[i]<=sum){
        temp2 = (1 + solve(n,i,a,sum-a[i],dp))%mod;
    }
    int temp = solve(n,i+1,a,sum,dp);
    return dp[i][sum] = min(temp,temp2)%mod;
}
int dp_tabulation(int n,int sum,int a[],vector<vector<int>> &dp){
    int mod = 1e9+7;
    for(int i=1;i<=sum;i++){
        dp[0][i] = 1e9;
    }
    for (int i = 1; i <= n; i++)
    {
       for (int j = 0; j <= sum; j++)
       {
          if(j<a[i-1]){
            dp[i][j] = dp[i-1][j]%mod;
          }else{
            dp[i][j] = min(1+dp[i][j-a[i-1]],dp[i-1][j])%mod;
          }
       }
    }
    if(dp[n][sum]==1e9) return -1;
    return dp[n][sum];
}
int main(){
    int n,sum;
    cin>>n>>sum;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    //Memoization
    // vector<vector<int>> dp(n,vector<int>(sum+1,-1));
    // int x = solve(n,0,a,sum,dp);
    // if(x>=1e9) x=-1;
    // cout<<x;
    //Tabulation
    vector<vector<int>> dp(n+1,vector<int>(sum+1,0));
    cout<<dp_tabulation(n,sum,a,dp);
 return 0;
}