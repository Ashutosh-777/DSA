#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,x;
    cin>>n>>x;
    vector<int> pages(n),price(n);
    for(int i=0;i<n;i++){
        cin>>price[i];
    }
    for(int i=0;i<n;i++){
        cin>>pages[i];
    }
    int sum = x;
    vector<vector<int>> dp(n+1,vector<int>(x+1,0));
    for(int i=price[0];i<=x;i++){
        dp[0][i] = pages[0];
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<=x;j++){
            if(j>=price[i]){
                dp[i][j] = max(pages[i] + dp[i-1][j-price[i]],dp[i-1][j]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout<<dp[n-1][x];
 return 0;
}