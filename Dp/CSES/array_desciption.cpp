#include <bits/stdc++.h>
using namespace std;
vector<vector<long long>> dp;
int mod = 1e9+7;
long long solve(vector<int> &a,int prev,int ind,int m){
    int n =a.size();
    if(ind==n) return 1;
    int ans = 0;
    if(dp[ind][prev]!=-1) return dp[ind][prev];
    if(a[ind]!=0){
        if(abs(a[ind]-prev)>1) return dp[ind][prev] =  0;
        else return dp[ind][prev] = solve(a,a[ind],ind+1,m)%mod;
    }
    if(prev+1<=m)
    ans=(ans + solve(a,prev+1,ind+1,m))%mod;
    ans=(ans + solve(a,prev,ind+1,m))%mod;
    if(prev!=1) ans=(ans+solve(a,prev-1,ind+1,m))%mod;
    return dp[ind][prev] =  ans%mod;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    long long ans = 0;
    if(a[0]==0){
        for(int i=1;i<=m;i++){
            a[0] = i;
            dp.resize(n+1,vector<long long>(m+1,-1));
            ans= (ans + solve(a,a[0],0,m))%mod;
            a[0] = 0;
        }
    }
    else{
        dp.resize(n+1,vector<long long>(m+1,-1));
        ans=(ans+solve(a,a[0],0,m))%mod;
    }
    cout<<ans<<endl;
 return 0;
}