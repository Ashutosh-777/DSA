#include <bits/stdc++.h>
using namespace std;
long long solve(long long n,vector<int>&dp){
    if(n<3) return 0;
    if(n<=9) return 1;
    if(dp[n]!=-1) return dp[n];
    long long numDigit = log10(n) + 1;
    long long base = pow(10,numDigit-1);
    long long rem = n%base;
    long long q = n/base;
    long long num = 0;
    int mult = 0;
    int x = solve(rem,dp);
    dp[rem] = x;
    if(q==3){
        mult = q;
        num = n-base*3+1;
    }else if(q>3){
        mult = q-1;
        num = x + base;
    }else if(q<3){
        mult=q;
        num=x;
    }
    return dp[n] = solve(base-1,dp)*mult+num;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        vector<int> dp(n+1,-1);
        cout<<n-solve(n,dp)<<endl;
    }
 return 0;
}