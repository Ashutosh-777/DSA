#include <bits/stdc++.h>
using namespace std;
#define lli long long int
lli dp[100001];
lli inv[100001];
lli getHash(string &s){
    int p = 31;
    lli power = 1;
    lli value = 0;
    int mod = 1e9+7;
    for(char ch:s){
        value =  (value + 1LL*(ch-'a'+1)*power)%mod;
        power = (power*p)%mod;
    }
    return value;
}
void preCompute(string &s){
    lli power = 1;
    int p = 31;
    lli value = 0;
    int  mod = 1e9+7;
    for(int i=0;i<n;i++){
        value = (value + (s[i]-'a'+1)*power)%mod;
        dp[i] = value;
        power = (power*p)%mod;
    }
}
lli getHash(string &s,int l,int r){
    if(l==0) return dp[r];
    return (dp[r]-dp[l-1])*inv[l];
}
int main(){
    string s;
    cin>>s;
    cout<<getHash(s)<<endl;
 return 0;
}