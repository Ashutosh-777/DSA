#include <bits/stdc++.h> 
//s = bag j = 2
//t = babgbag i = 6
// int ans[1001][1001];
// int solve(string &t,string &s,int i,int j){
//     if(ans[i][j]!=-1) return ans[i][j];
//     if(j==0) return ans[i][j] = 1;
//     if(i==0) return ans[i][j] = 0;
//     if(t[i-1]==s[j-1]){
//         return ans[i][j] = (solve(t,s,i-1,j-1) + solve(t,s,i-1,j));
//     }else return ans[i][j] = solve(t,s,i-1,j);
// }
int subsequenceCounting(string &t, string &s, int lt, int ls) {
    int ans[lt+1][ls+1];
    int mod=1e9+7;
    // memset(ans,-1,sizeof(ans));
    // return  solve(t,s,lt,ls);
    for(int i=0;i<=lt;i++){
        for(int j=0;j<=ls;j++){
            if(i==0&&j!=0){
                ans[i][j]=0;
                continue;
            }
            if(j==0){
                ans[i][j]=1;
                continue;
            }
            if(t[i-1]==s[j-1]){
                ans[i][j] = (ans[i-1][j-1] + ans[i-1][j])%mod;
            }else{
                ans[i][j] = (ans[i-1][j])%mod;
            }
        }
    }
    return ans[lt][ls];
} 