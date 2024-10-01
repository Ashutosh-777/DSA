#include <bits/stdc++.h>
using namespace std;
// vector<vector<int>> dp;
int mod = 1e9+7;
// int solve(vector<int> &a,int sum,int ind){
//     int n =a.size();
//     if(sum==0) return 1;
//     if(sum<0||ind==n) return 0;
//     if(dp[sum][ind]!=-1) return dp[sum][ind];
//     return dp[sum][ind] = (solve(a,sum-a[ind],ind) + solve(a,sum,ind+1))%mod;
// }
int solve_tab(vector<int> &a,int sum){
    int n =a.size();
    vector<vector<int>> dp(sum+1,vector<int>(n+1,0));
    for(int i=0;i<=n;i++){
        dp[0][i] = 1;
    }
    for(int j=1;j<=sum;j++){
        for(int i=1;i<=n;i++){
            if(j>=a[i-1]){
                dp[j][i] = (dp[j-a[i-1]][i] + dp[j][i-1])%mod;
            }else{
                dp[j][i] = dp[j][i-1];
            }
        }
    }
    return dp[sum][n];
}
int32_t main(){
    int n,x;
    cin>>n>>x;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    // dp.resize(x+1,vector<int>(n+1,-1));
    // cout<<solve(a,x,0)<<endl;
    cout<<solve_tab(a,x)<<endl;
 return 0;
}