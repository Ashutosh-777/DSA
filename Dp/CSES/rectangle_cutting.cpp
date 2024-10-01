#include <bits/stdc++.h>
using namespace std;
int isNotValid(int i,int j,int a,int b){
    if(i==0&&j==0) return true;
    if(i==a&&j==b) return true;
    if(i==0&&j==b) return true;
    if(i==a&&j==0) return true;
    return false;
}
vector<vector<long long>> dp;
// long long solve(int a,int b){
//     if(a==b) return 0;
//     if(a==0||b==0) return 0;
//     long long ans = 1e9;
//     if(dp[a][b]!=-1) return dp[a][b];
//     for(int i=1;i<=min(a,b);i++){
//         // for(int j=0;j<=b;j++){
//             if(isNotValid(i,i,a,b)) continue;
//             long long x = solve(i,b-i);
//             long long y = solve(a-i,i);
//             long long z = solve(a-i,b-i);
//             int w = 0;
//             if(i!=min(a,b)) w=1;
//             ans = min(ans,1+w+x+y+z);
//         // }
//     }
//     return dp[a][b] =  ans;
// }
long long solve(int a,int b){
    if(a==b) return 0;
    long long ans = 1e9;
    if(dp[a][b]!=-1) return dp[a][b];
    for(int i=1;i<a;i++){
        ans = min(ans,1+solve(i,b)+solve(a-i,b));
    }
    for(int j=1;j<b;j++){
        ans = min(ans,1+solve(a,j)+solve(a,b-j));
    }
    return dp[a][b] =  ans;
}
int main(){
    int a,b;
    cin>>a>>b;
    // dp.resize(a+1,vector<long long>(b+1,-1));
    //cout<<solve(a,b)<<endl;
    //tabulation
    dp.resize(a+1,vector<long long>(b+1,1e9));
    for(int i=0;i<=a;i++){
        for(int j=0;j<=b;j++){
            if(i==j) dp[i][j] = 0;
            else{
                for(int k=1;k<i;k++){
                    dp[i][j] = min(dp[i][j],1+dp[k][j] + dp[i-k][j]);
                }
                for(int k=1;k<j;k++){
                    dp[i][j] = min(dp[i][j],1+dp[i][k]+dp[i][j-k]);
                }
            }
        }
    }
    cout<<dp[a][b];
 return 0;
}