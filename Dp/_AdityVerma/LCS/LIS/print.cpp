#include <bits/stdc++.h>
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int> dp(n,1),hash(n);
    int maxi = -1;
    int lastind = 0;
    for(int curr=0;curr<n;curr++){
        hash[curr] = curr;
        for(int prev=0;prev<curr;prev++){
            if(arr[prev]<arr[curr]&&dp[curr]<1+dp[prev]){
                dp[curr] = 1 + dp[prev];
                hash[curr] = prev;
            }
        }
        if(maxi<dp[curr]){
            maxi=dp[curr];
            lastind = curr;
        }
        // maxi = max(maxi,dp[curr]);
    }
        vector<int> ans;
        ans.push_back(arr[lastind]);
        while(hash[lastind]!=lastind){
            lastind = hash[lastind];
            ans.push_back(arr[lastind]);
        }
        reverse(ans.begin(),ans.end());
        for( auto &it: ans) cout<<it<<" ";
        cout<<endl;
    return maxi;
}
