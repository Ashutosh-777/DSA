#include <bits/stdc++.h>
using namespace std;
//int dp[index][tight][prev]
long long dp[20][2][11];
long long solve(string s,int ind,int tight,int prev){
    int n = s.size();
    if(ind==n) return 1;
    if(dp[ind][tight][prev+1]!=-1) return dp[ind][tight][prev+1];
    int limit = (tight==1)?s[ind]-'0':9;
    long long ans = 0;
    for(int i=0;i<=limit;i++){
        int updatedTight = tight&&(s[ind]-'0'==i);
        if(prev==-1&&i==0) {ans+=solve(s,ind+1,updatedTight,prev); continue;}
        if(prev==-1||prev!=i)
        ans+=solve(s,ind+1,updatedTight,i);
    }
    return dp[ind][tight][prev+1] = ans;
}
int main(){
    long long a,b;
    cin>>a>>b;
    a--;
    string left = to_string(a);
    string right = to_string(b);
    memset(dp,-1,sizeof(dp));
    long long r = solve(right,0,1,-1);
    memset(dp,-1,sizeof(dp));
    long long l  = solve(left,0,1,-1);
    cout<<r-l<<endl;
 return 0;
}
