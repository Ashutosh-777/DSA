//PROBLEM LINK DIGIT COUNT
//https://lightoj.com/problem/digit-count
// #include <bits/stdc++.h>
// using namespace std;
// int dp[11][11][3];
// int solve(vector<int> &v,int idx,int prev,int d,int n){
//     if(idx>=v.size()) return 1;
//     if(d==n) return 1;
//     int ans = 0;
//     if(dp[idx][prev+1][d]!=-1) return dp[idx][prev+1][d];
//     for(int i=0;i<v.size();i++){
//         if(prev==-1||abs(v[i]-prev)<=2){
//             ans+=solve(v,i,v[i],d+1,n);
//         }
//     }
//     return dp[idx][prev+1][d] = ans;
// }
// int main(){
//     int t;
//     cin>>t;
//         int z = t;
//     while(t--){
//         int m,n;
//         cin>>m>>n;
//         vector<int> v(m,0);
//         for(int i=0;i<m;i++){
//             cin>>v[i];
//         }
//         memset(dp,-1,sizeof(dp));
//         cout<<"Case "<<z-t<<": "<<solve(v,0,-1,0,n)<<endl;
//     }
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
int dp[110][110];
int solve(vector<int> &v,int idx,int prev,int n){
    if(idx==n) return 1;
    int ans = 0;
    if(dp[idx][prev+1]!=-1) return dp[idx][prev+1];
    for(int i=0;i<int(v.size());i++){
        if(prev==-1||abs(v[i]-prev)<=2){
            ans+=solve(v,idx+1,v[i],n);
        }
    }
    return ans;
    return dp[idx][prev+1]= ans;
}
int main(){
    int t;
    cin>>t;
        int z = t;
    while(t--){
        int m,n;
        cin>>m>>n;
        vector<int> v(m,0);
        for(int i=0;i<m;i++){
            cin>>v[i];
        }
        memset(dp,-1,sizeof(dp));
        cout<<"Case "<<z-t<<": "<<solve(v,0,-1,n)<<endl;
    }
    return 0;
}