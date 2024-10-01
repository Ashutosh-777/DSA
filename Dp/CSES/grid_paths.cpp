#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<vector<char>> v(n,vector<char>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>v[i][j];
        }
    }
    vector<vector<int>> dp(n,vector<int>(n,0));
    if(v[0][0]=='*'||v[n-1][n-1]=='*'){
        cout<<0<<endl;
        return 0;
    }
    dp[0][0] = 1;
    //1st row
    for(int j=1;j<n;j++){
        if(v[0][j]=='*') break;
        dp[0][j]  = 1;
    }
    //1st column
    for(int i=1;i<n;i++){
        if(v[i][0]=='*') break;
        dp[i][0] = 1;
    }
    int mod = 1e9+7;
    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            if(v[i][j]=='*') continue;
            if(i-1>=0){
                dp[i][j]+=dp[i-1][j];
            }
            if(j-1>=0){
                dp[i][j]+=dp[i][j-1];
            }
            dp[i][j]%=mod;
        }
    }
    cout<<dp[n-1][n-1]<<endl;
 return 0;
}