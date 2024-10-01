#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,x;
    cin>>n>>x;
    int w[n];
    for(int i=0;i<n;i++){
        cin>>w[i];
    }
    int maxState = 1<<n;
    vector<pair<int,int>> dp(maxState,{n,x});
    dp[0] = {0,0};
    for(int mask=1;mask<maxState;mask++){
        for(int j=0;j<n;j++){
            if(mask&(1<<j)){
                int prevState = mask^(1<<j);
                int num = dp[prevState].first;
                int wt = dp[prevState].second;
                if(wt+w[j]<=x){
                    dp[mask] = min(dp[mask],{num,wt+w[j]});
                }else{
                    dp[mask] = min(dp[mask],{num+1,w[j]});
                }
            }
        }
    }
    cout<<dp[maxState-1].first+1<<endl;
 return 0;
}