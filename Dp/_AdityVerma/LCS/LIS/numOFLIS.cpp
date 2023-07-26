#include <bits/stdc++.h> 
int findNumberOfLIS(vector<int> &arr)
{
    int n = arr.size();
    vector<int> dp(n,1),cnt(n,1);
    int maxi = 1 ;

    for(int curr=0;curr<n;curr++){
        for(int prev=0;prev<curr;prev++){
            if(arr[prev]<arr[curr]&&1+dp[prev]>dp[curr]){
                dp[curr ] =dp[prev]+1;
                cnt[curr] = cnt[prev];
            }else if(arr[prev]<arr[curr]&&1+dp[prev]==dp[curr]){
                cnt[curr]+=cnt[prev];
            }
        }
        maxi = max(maxi,dp[curr]);
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        if(dp[i]==maxi){
            ans+=cnt[i];
        }
    }
    return ans;
}