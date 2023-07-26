#include <bits/stdc++.h>
using namespace std;
int dp[1001];
#define mod 1000000007
int f(int n){
    if(dp[n]!=-1) return dp[n];
    if(n==0||n==1) return 1;
    int i=0;
    int j = n-1;
    int ans = 0;
    while(i<=n-1&&j>=0){
        ans += f(i)*f(j);
        i++;
        j--;
        ans = ans%mod;
    }
    return dp[n] = ans%mod;
}
int chordCnt(int A) {
    vector<long long> C(2*A+1,1);
    for(int chords = 2; chords <= 2*A; chords += 2){
        for(int a=0,b=chords-2;b>=0;a+=2,b-=2){
            C[chords] += C[a]*C[b];
            C[chords] %= 1000000007;
        }
    }
    return C[2*A];
}
int main(){
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<=23;i++) cout<<f(i)<<" ";
    cout<<endl;
    for(int i=0;i<=23;i++) cout<<chordCnt(i)<<' ';
    cout<<endl;
 return 0;
}