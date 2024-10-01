#include <bits/stdc++.h>
using namespace std;
vector<vector<long long>> dp;
long long solve(int a[],int i,int j){
    if(i>j) return 0;
    if(i==j) return a[i];
    if(dp[i][j]!=-1) return dp[i][j];
    long long x = solve(a,i+1,j-1);
    long long left = a[i] + min(solve(a,i+2,j),x);
    long long right = a[j] + min(x,solve(a,i,j-2));
    return dp[i][j] =  max(left,right);
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    dp.resize(n+1,vector<long long>(n+1,-1));
    cout<<solve(a,0,n-1);
 return 0;
}