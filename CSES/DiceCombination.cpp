#include <bits/stdc++.h>
using namespace std;
#define v2 vector<vector<int>>
int solve(int n){
    vector<int> dp(n+1,0);
    dp[0]=1;
    int mod =1e9+7;
        for(int sum=1;sum<=n;sum++){
            for(int i=1;i<=6;i++){
                if(sum>=i){
                    dp[sum] = (dp[sum]+dp[sum-i])%mod;
                }
            }
        }
    return dp[n];
}
 
int main(){
    int n;
    cin>>n;
    cout<<solve(n)<<endl;
 return 0;
}
