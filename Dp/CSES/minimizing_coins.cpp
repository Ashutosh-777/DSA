#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;
//need to be tabulized otherwise won't pass on CSES
int solve(int a[],int n,int x,int ind){
    if(x==0) return 0;
    if(x<0) return 1e9;
    if(dp[x][ind]!=-1) return dp[x][ind];
    if(ind == n) return 1e9;
    return dp[x][ind] =  min(1+solve(a,n,x-a[ind],ind),solve(a,n,x,ind+1));
}
int main(){
    int n,x;
    cin>>n>>x;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    dp.resize(x+1,vector<int>(n+1,-1));
    int y = solve(a,n,x,0);
    if(y>=1e9) cout<<-1<<endl;
    else cout<<y<<endl;
 return 0;
}