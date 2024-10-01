#include <bits/stdc++.h>
using namespace std;
int dp[20][2][20];
int solve(string &s,int idx,int tight,int cnt){
    if(idx==s.size()){
        if(cnt>3) return 0;
        return 1;
    }
    if(dp[idx][tight][cnt]!=-1) return dp[idx][tight][cnt];
    int limit = (tight==1? s[idx]-'0':9);
    int ans = 0;
    for(int i=0;i<=limit;i++){
        int updatedCnt = cnt+(i>0?1:0);
        int updatedTight = tight&(limit==i);
        ans+= solve(s,idx+1,updatedTight,updatedCnt);
    }
    return dp[idx][tight][cnt] = ans;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        string l,r;
        cin>>l>>r;
        memset(dp,-1,sizeof(dp));
        int right = solve(r,0,1,0);
        memset(dp,-1,sizeof(dp));
        int left = solve(l,0,1,0);
        int cnt = l.size();
        for(auto it:l){
            if(it=='0') cnt--;
        }
        int ans = right-left;
        if(cnt<=3){
            ans++;
        }
        cout<<ans<<endl;
    }
 return 0;
}