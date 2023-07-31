#include <bits/stdc++.h>
using namespace std;
int fun(vector<int>&A,int i,int sum,vector<vector<int>>&dp){
    
    int n =A.size();
    if(sum==0) return 1;
    if(i>=n) return 0;
    int a =0;
    if(dp[i][sum]!=-1) return dp[i][sum];
    if(A[i]<=sum) a= fun(A,i+1,sum-A[i],dp);
    int b = fun(A,i+1,sum,dp);
    return dp[i][sum] =  a||b;
}
int solve(vector<int> &A) {
    int sum = 0;
    int n = A.size();
    for(int i=0;i<n;i++) sum += A[i];
    int s1 = sum/2;
    vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
    int ans = fun(A,0,sum,dp);
    int x = 0;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=s1;j++){
            if(dp[i][j]) x= max(x,j);
            
        }
    }
    if(x==0) return -1;
    return sum-2*x;
}

int main(){
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    cout<<endl;
    cout<<solve(v);
    cout<<"hello";
 return 0;
}