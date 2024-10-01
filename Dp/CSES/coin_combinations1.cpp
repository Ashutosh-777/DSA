#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
vector<int> dp;
int solve(vector<int> &a,int sum){
    int n =a.size();
    if(sum==0) return 1;
    if(sum<0) return 0;
    if(dp[sum]!=-1) return dp[sum];
    int ans = 0;
    for(int i=0;i<n;i++){
        ans+= solve(a,sum-a[i]);
        ans%=mod;
    }
    return dp[sum] =  ans;
}
// int tabulized(vector<int> &a,int sum){
//     vector<int> dp(sum+1,0);
//     dp[0] = 1;
//     int n =a.size();
//     for(int j=1;j<=sum;j++){
//         for(int i=0;i<n;i++){
//             if(a[i]<=j){
//                 dp[j] += dp[j-a[i]];
//                 dp[j]%=mod;
//             }
//         }
//     }
//     return dp[sum];
// }
int main(){
    std::ios::sync_with_stdio(false);
    
    // Untie cin from cout, so they don't flush automatically on each input/output operation
    std::cin.tie(nullptr);
    int n,x;
    cin>>n>>x;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    dp.resize(x+1,-1);
    cout<<solve(a,x)<<"\n";
    // cout<<tabulized(a,x);
 return 0;
}