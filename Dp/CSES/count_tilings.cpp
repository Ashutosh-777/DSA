// #include <bits/stdc++.h>
// using namespace std;
// int mod = 1e9+7;
// // int solve(int n,int m,int i,int j,int curr,int next){
// //     //base case
// //     if(j==m) return curr==0;
// //     if(i==n){
// //         return solve(n,m,0,j+1,next,0);
// //     }
// //     if((curr&(1<<i))==0){
// //         if(i+1==n){
// //             return solve(n,m,i+1,j,curr|(1<<i),next|(1<<i));
// //         }
// //         if(curr&(1<<(i+1))){
// //             return solve(n,m,i+1,j+1,curr|(1<<i),next|(1<<i));
// //         }
// //         return solve(n,m,i+1,j,curr|(1<<i),next|(1<<i)) + solve(n,m,i+2,j,curr|(1<<i)|(1<<(i+1)),next);
// //     }
// //     //shi
// //     return solve(n,m,i+1,j,curr,next);
// // }
// void generateMasks(int n,int i,int mask,int next,vector<int> &masks){

//     if(i==n){
//         masks.push_back(next);
//         return;
//     }
//     if(mask&(1<<i)){
//         generateMasks(n,i+1,mask,next,masks);
//         return;
//     }
//     if((i+1!=n)&&!(mask&(1<<(i+1)))){
//         generateMasks(n,i+2,mask|(1<<i)|(1<<(i+1)),next,masks);
//         // generateMasks(n,i+1,mask|(1<<i),next|(1<<i),masks);
//         // return;
//     }
//     generateMasks(n,i+1,mask|(1<<i),next|(1<<i),masks);
// }
// vector<vector<int>> dp;
// int solve(int n,int m,int currMask,int j){
//     if(j==m) return currMask == 0;
//     if(dp[j][currMask]!=-1) return dp[j][currMask];
//     vector<int> masks;
//     generateMasks(n,0,currMask,0,masks);
//     long long ans = 0;
//     for(auto curr:masks){
//         ans+=solve(n,m,curr,j+1);
//         ans%=mod;
//     }
//     return dp[j][currMask] = ans;
// }
// int main(){
//     int n,m;
//     cin>>n>>m;
//     if((n*m)%2){
//         cout<<0<<endl;
//         return 0;
//     }
//     dp.resize(m+1,vector<int>(1<<n,-1));
//     cout<<solve(n,m,0,0)<<endl;
//  return 0;
// }
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define ff first
#define ss second
using namespace std;
template <typename T>
using bstring = basic_string<T>;
template <typename T>
using matrix = vector<vector<T>>;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll INFL = (1LL<<62)-1;
const int INF = (1<<30)-1;
const double EPS = 1e-7;
const int MOD = 1e9+7;
const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
const int MAXN = 11, MAXM = 1001;
 
ll dp[MAXM][MAXN][1<<MAXN];
 
int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
 
    dp[0][n][0] = 1; // initially it's like the "0th" column is filled but nothing is sticking into the 1st column
 
    for(int i = 1; i <= m; i++){
 
        for(int mask = 0; mask < (1<<n); mask++)
            dp[i][0][mask] = dp[i-1][n][mask]; // unformed part of ith column is the formed part of the (i-1)th column
 
        for(int j = 1; j <= n; j++){
            for(int mask = 0; mask < (1<<n); mask++){
 
                bool use = (1<<j-1)&mask;
 
                if(use){
                    dp[i][j][mask]+=dp[i][j-1][mask-(1<<j-1)]; // placing a horizontal tile on an empty place
                } else {
                    dp[i][j][mask]+=dp[i][j-1][mask+(1<<j-1)]; // not placing anything on a filled place
                    if(j > 1 && !((1<<j-2)&mask)) 
                        dp[i][j][mask]+=dp[i][j-2][mask]; // placing a vertical tile on 2 empty spaces
                }
 
                dp[i][j][mask]%=MOD;
 
            }
        }
    }
 
    cout << dp[m][n][0] << '\n'; // the answer is filling the first m columns with nothing sticking out
    
    return 0;
 
}