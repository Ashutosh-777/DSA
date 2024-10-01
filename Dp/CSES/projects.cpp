#include <bits/stdc++.h>
using namespace std;
vector<long long> dp;
long long solve(vector<vector<long long>> &a,long long ind,vector<long long> &v){
    if(ind==0) return 0;
    if(dp[ind]!=-1) return dp[ind];
    long long pick = a[ind-1][2];
    long long nxt = lower_bound(v.begin(),v.end(),a[ind-1][0])-v.begin();
    pick+=solve(a,nxt,v);
    long long notPick = solve(a,ind-1,v);
    return dp[ind] =  max(pick,notPick);
}
static bool cmp(vector<long long> &a,vector<long long> &b){
    return a[1]<b[1];
}
int main(){
    long long n;
    cin>>n;
    vector<vector<long long>> a(n,vector<long long>(3));
    for(long long i=0;i<n;i++){
        for(long long j =0;j<3;j++){
            cin>>a[i][j];
        }
    }
    sort(a.begin(),a.end(),cmp);
    vector<long long> v;
    for(long long i=0;i<n;i++) v.push_back(a[i][1]);
    dp.resize(n+1,-1);
    cout<<solve(a,n,v);
 return 0;
}