#include <bits/stdc++.h>
using namespace std;
int solve(int n,int a[],int sum){
    vector<vector<int>> dp(n+1,vector<int>(sum+1,0));
    dp[0][0]=1;
    int mod = 1e9+7;
        for(int j=0;j<=sum;j++){
    for(int i=1;i<=n;i++){
            if(j<a[i-1]){
                dp[i][j] = dp[i-1][j];
            }else{
                dp[i][j] =( dp[i][j-a[i-1]] + dp[i-1][j])%mod;
            }
        }
    }
return dp[n][sum];
}
int main(){
    int n,sum;
    cin>>n>>sum;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<solve(n,a,sum);
 return 0;
}
