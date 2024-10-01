#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int sum = n*(n+1)/2;
    if(sum%2){
        cout<<0<<endl;
        return 0;
    }
    int mod = 1e9+7;
    sum/=2;
    vector<vector<int>> dp(n+1,vector< int>(sum+1,0));
    dp[0][0] = 1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=sum;j++){
            if(j>=i){
                dp[i][j] = (dp[i-1][j-i]+dp[i-1][j])%mod;
            }else{
                dp[i][j] += dp[i-1][j];
            }
            dp[i][j]%=mod;
        }
    }
    long long x = (1LL*dp[n][sum]*500000004)%mod;
    cout<<x<<endl;
 return 0;
}