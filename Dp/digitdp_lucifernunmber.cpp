#include <bits/stdc++.h>
using namespace std;
//dp[idx][tight][eve][odd]
int dp[12][2][110][110];
int isPrime(int n){
    if(n<2) return 0;
    for(int i=2;i<n;i++ ){
        if(n%i==0) return false;
    }
    return true;
}
bool check(int evenSum, int oddSum, int size){
    cout<<evenSum-oddSum<<" : "<<oddSum-evenSum<<" size: "<<size<<endl;
    if(size%2 == 0){
        return isPrime(evenSum - oddSum);
    }
    else{
        return isPrime(oddSum - evenSum);
    }
}
int solve(string s,int idx,int tight,int eve,int odd){
    int n =s.size();
    if(idx==n){
        // return  isPrime(abs(eve-odd));
        return check(eve, odd, s.size());
    }
    if(dp[idx][tight][eve][odd]!=-1) return dp[idx][tight][eve][odd];
    int limit = tight==1?s[idx]-'0':9;
    int ans = 0;
    for(int i=0;i<=limit;i++){
        int updatedTight = (tight==1)&&(limit==i);
        int ueve = eve;
        int uodd = odd;
        if(idx%2==0) ueve+=i;
        else uodd+=i;
        ans+=solve(s,idx+1,updatedTight,ueve,uodd);
    }
    // return ans;
    return dp[idx][tight][eve][odd] =  ans;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>b>>a;
        string r = to_string(a);
        string l = to_string(b-1);
        memset(dp,-1,sizeof(dp));
        int x= solve(r,0,1,0,0);
        memset(dp,-1,sizeof(dp));
        int y = solve(l,0,1,0,0);
        cout<<x-y<<endl;
    }
 return 0;
}