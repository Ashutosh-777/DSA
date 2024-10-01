// #include <bits/stdc++.h>
// using namespace std;
// set<int> st;
// vector<vector<int>> dp;
// void solve(vector<int> &v,int i,int sum){
//     int n =v.size();
//     if(dp[i][sum]) return;
//     if(i==n){
//         if(sum)
//         st.insert(sum);
//         return;
//     }
//     //pick
//     solve(v,i+1,sum+v[i]);
//     //not pick
//     solve(v,i+1,sum);
//     dp[i][sum] = 1;
// }
// int main(){
//     int n;
//     cin>>n;
//     vector<int> v(n);
//     st.clear();
//     int x =0;
//     for(int i=0;i<n;i++){
//         cin>>v[i];
//         x+=v[i];
//     }
//     dp.resize(n+1,vector<int>(x+1,0));
//     solve(v,0,0);
//     cout<<st.size()<<endl;
//     for(auto it:st){
//         cout<<it<<" ";
//     }
//  return 0;
// }
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    int sum = 0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    vector<vector<int>> dp(n+1,vector<int>(sum+1,0));
    for(int i=0;i<=n;i++) dp[i][0] = 1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            dp[i][j] = dp[i-1][j];
            if(j>=a[i-1]&&dp[i-1][j-a[i-1]]){
                dp[i][j] = 1;
            }
        }
    }
    int cnt = 0;
    for(int j=1;j<=sum;j++){
        if(dp[n][j]) cnt++;
    }
    cout<<cnt<<endl;
    for(int j=1;j<=sum;j++){
        if(dp[n][j]) cout<<j<<" ";
    }
 return 0;
}