#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,x;
    cin>>n>>x;
    int price[n],page[n];
    for(int i=0;i<n;i++){
        cin>>price[i];
    }
    for(int i=0;i<n;i++){
        cin>>page[i];
    }
    vector<vector<int>> dp(n+1,vector<int>(x+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=x;j++){
            int take = 0;
            if(price[i-1]<=j){
                take = dp[i-1][j-price[i-1]]+page[i-1];
            }
            dp[i][j] = max(take,dp[i-1][j]);
        }
    }
    cout << dp[n][x] << endl;
 return 0;
}
