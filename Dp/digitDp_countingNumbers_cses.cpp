#include <bits/stdc++.h>
using namespace std;
//dp[idx][tight][prev]
long long dp[20][2][12];
long long solve(string s,long long idx,long long tight,long long prev){
    if(idx==s.size()) return 1;
    long long limit = (tight?s[idx]-'0':9);
    long long ans = 0;
    if(dp[idx][tight][prev+1]!=-1) return dp[idx][tight][prev+1];
    // cout<<limit<<" :limit"<<" prev: "<<prev<<endl;
    for(long long i=0;i<=limit;i++){
        long long updatedTight = tight&&(limit==i);
        //need to add dthis to counter problem which occur due to following reason
        // for 100 
        //if we take first digit as 0 then we can take next digit 0 also to get 001 or 002 or 003 numbers 
        //but we don't identify leading zeros we will not consider 001 002 because it has  two consecutive 
        //digit same 00 but since they are leading they doesnot count
        if(prev==-1&&i==0) {ans+=solve(s,idx+1,updatedTight,prev); continue;}
        if(prev==-1||prev!=i)
        ans+=solve(s,idx+1,updatedTight,i);
    }
    // cout<<" ans: "<<ans<<endl;
    // return ans;
    return dp[idx][tight][prev+1] =  ans;
}
int main(){
    // int t;
    // cin>>t;
    // while(t--){
        long long l,r;
        cin>>l>>r;
        string left = to_string(l-1);
        string right = to_string(r);
        // cout<<"right: "<<right[0]<<"\n";
        // cout<<solve(right,1,0,0);
        memset(dp,-1,sizeof(dp));
        long long leftAns = solve(left,0,1,-1);
        memset(dp,-1,sizeof(dp));
        long long rightAns = solve(right,0,1,-1);
        // cout<<"left: "<<leftAns<<endl;
        // cout<<"right: "<<rightAns<<endl;
        cout<<rightAns-leftAns<<endl;
    // }
 return 0;
}