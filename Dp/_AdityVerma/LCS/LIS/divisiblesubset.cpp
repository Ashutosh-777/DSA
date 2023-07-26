#include <bits/stdc++.h> 
using namespace std;
int solve(int curr,int maxi,vector<int>&arr){
    if(curr==arr.size()) return 0;
    int x=INT_MIN;
    int y;
    int prevMaxi = maxi;
    if(maxi==-1||(arr[maxi]%arr[curr])==0||(arr[curr]%arr[maxi])==0){
        if(maxi==-1||arr[maxi]<arr[curr]){
            maxi = curr;
        }
        x = 1 + solve(curr+1,maxi,arr);
    }
    y = solve(curr+1,prevMaxi,arr);
    return max(x,y);
}
int  divisibleSet(vector<int> &arr){
    sort(arr.begin(),arr.end());
    int cnt =  solve(0,-1,arr);
    return cnt;
    // Write your code here.
}
#include <bits/stdc++.h> 
#include <bits/stdc++.h>
// int solve(int curr,int prev,vector<int>&arr,vector<int> &v){
//     if(curr==arr.size()) return 0;
//     int x=INT_MIN;
//     int y;
//     if(prev==-1||(arr[curr]%arr[prev])==0){
//         x = 1 + solve(curr+1,curr,arr,v);
//     }
//     y = solve(curr+1,prev,arr,v);
//     return max(y,x);
// }
// vector<int> divisibleSet(vector<int> &arr){
//     sort(arr.begin(),arr.end());
//     int cnt =  solve(0,-1,arr,ans);
//     return {};
// }
vector<int> divisibleSet(vector<int> &arr){
    int n = arr.size();
    sort(arr.begin(),arr.end());
    vector<int> dp(n,1),hash(n);
    int cnt = 0;
    int lastind = 0;
    for(int i=0;i<n;i++){
        hash[i] = i;
        for(int prev = 0 ;prev<i;prev++){
            if(arr[i]%arr[prev] == 0&&dp[i]<dp[prev]+1){
            dp[i] = dp[prev]+1;
            hash[i] = prev;
            }
        }
        if(cnt<dp[i]){
            cnt=dp[i];
            lastind = i;
        }
    }
    //cnt is the count of largest divisible set
    vector<int> ans;
    ans.push_back(arr[lastind]);
    while(hash[lastind]!=lastind){
        lastind = hash[lastind];
        ans.push_back(arr[lastind]);
    }
    
    return ans;
    // Write your code here.
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v;
        for(int i=0;i<n;i++){
            int c;
            cin>>c;
            v.push_back(c);
        }
        cout<<divisibleSet(v)<<endl;
    }
 return 0;
}