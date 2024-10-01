//  Problem Link
//  https://www.hackerearth.com/problem/algorithm/benny-and-the-broken-odometer/
#include <bits/stdc++.h>
using namespace std;
//dp[idx][tight][is3]
int dp[11][2][2];
int solve(string &s,int idx,int tight,int is3){
    if(idx==s.size()){
        return is3;
    }
    if(dp[idx][tight][is3]!=-1) return dp[idx][tight][is3];
    int limit = (tight==1?s[idx]-'0':9);
    int ans = 0;
    for(int i=0;i<=limit;i++){
        int updatedTight=tight&(limit==i);
        // cout<<"i: "<<i<<endl;
        if(is3){
            int x = solve(s,idx+1,updatedTight,is3);
            // cout<<"14: "<<x<<endl;
            ans+=x;
        }else{
            int updatedIs3 = (i==3);
            int x = solve(s,idx+1,updatedTight,updatedIs3);
            ans+=x;
            // cout<<"21: "<<x<<endl;
        }
    }
    return  dp[idx][tight][is3]=ans;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s = to_string(n);
        memset(dp,-1,sizeof(dp));
        cout<<n-solve(s,0,1,0)<<endl;
    }
 return 0;
}