#include <bits/stdc++.h>
using namespace std;
int solve(vector<vector<int>> &a,int i,int j){
    int n =a.size();
    if(i==n) return 0;
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>> a(n,vector<int>(4)),v1(n),v2(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            cin>>a[i][j];
            if(j==0) v1[i] = a[i][0];
            if(j==1) v2[i] = a[i][1];
        }
        a[i][3] = i;
    }
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++){
        a[i][3]=i;
    }
    vector<vector<int>> v; 
    int ans = 0;
    for(int i=0;i<n;i++){
        if(v.size()==0||v.back()[1]<a[i][0]){
            v.push_back(a[i]);
            dp[i] = a[i][2] + 
        }
    }
 return 0;
}