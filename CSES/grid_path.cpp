#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            char ch;
            cin>>ch;
            if(ch=='.'){
                a[i][j]=1;
            }else if(ch=='*'){
                a[i][j]=0;
            }
        }
    }
    vector<vector<int>> dp(n,vector<int>(n,0));
    int mod = 1e9+7;
    if(!a[0][0]){
        cout<<0<<endl;
        return 0;
    }
    dp[0][0]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==0&&j==0){
                continue;
            }
            if(a[i][j]==0){
                dp[i][j]=0;
                continue;
            }
            int up = 0;
            int left = 0;
            if(j-1>=0){
                left = dp[i][j-1];
            }
            if(i-1>=0){
                up = dp[i-1][j];
            }
            dp[i][j] = (left + up)%mod;
        }
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<a[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    cout<<dp[n-1][n-1]<<endl;
 return 0;
}