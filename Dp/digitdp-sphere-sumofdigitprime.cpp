
//problem link
//https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqbDZVZ0tQMVFoWE9FcWhTZEcwcjBnZlpiNXNHZ3xBQ3Jtc0tsenkyaU5aMkVXVE1YMThRVjUwZU9oZ2g4TnJUcXFkWFRGeTRiRDQ1azZuUkh6cnB6TTF3RkVjQ29EOThNOWhlV0V5cXdTRXdMM21mNWVyalJieHpnamUxaXh5OTR3TWYwLTBsakJ4YnU5Q0FoSVVlZw&q=https%3A%2F%2Fwww.spoj.com%2Fproblems%2FGONE%2F&v=Jh2OZODnjfU
#include <bits/stdc++.h>
using namespace std;
int dp[20][2][80];
int prime[200];
int solve(string &s,int idx,int tight,int cnt){
    if(idx==s.size()){
        if(prime[cnt]) return 1;
        else return 0;
    }
    if(dp[idx][tight][cnt]!=-1) return dp[idx][tight][cnt];
    int limit = (tight==1? s[idx]-'0':9);
    int ans = 0;
    for(int i=0;i<=limit;i++){
        int updatedCnt = cnt+i;
        int updatedTight = tight&(limit==i);
        ans+= solve(s,idx+1,updatedTight,updatedCnt);
    }
    return dp[idx][tight][cnt] = ans;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        long long l,r;
        cin>>l>>r;
        string ls = to_string(l-1);
        string rs = to_string(r);
        memset(prime,1,sizeof(prime));
        prime[0]=0;
        prime[1]=0;
        for(int i=2;i*i<200;i++){
            if(prime[i]){
                int j = i*i;
                while(j<200){
                    prime[j]=0;
                    j+=i;
                }
            }
        }
        memset(dp,-1,sizeof(dp));
        int right = solve(rs,0,1,0);
        memset(dp,-1,sizeof(dp));
        int left = solve(ls,0,1,0);
        int ans = right-left;
        cout<<ans<<endl;
    }
 return 0;
}