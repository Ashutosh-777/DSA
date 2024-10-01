#include <bits/stdc++.h>
using namespace std;
//greedy no need to call solve evry time
int solve(int n,vector<int> &dp){
    if(n<10) return 1; 
    int k = n;
    int ans = INT_MAX;
    if(dp[n]!=-1) return dp[n];
    int x = 0;
    while(k){
        int ld = k%10;
        k/=10;
        x = max(x,ld);
        // int temp = 1 + solve(n-ld,dp);
        // ans = min(ans,temp);
    }
    return dp[n] = 1 +  solve(n-x,dp);
}
int main(){
    int n;
    cin>>n;
    vector<int> dp(n+1,-1);
    cout<<solve(n,dp);
 return 0;
}