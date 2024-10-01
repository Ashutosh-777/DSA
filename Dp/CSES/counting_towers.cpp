#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n],maxi=1;
    for(int i=0;i<n;i++){
        cin>>a[i];
        maxi = max(maxi,a[i]);
    }
    vector<long long> an(maxi+1,0),bn(maxi+1,0);
    an[1] = 1;
    bn[1] = 1;
    int mod = 1e9+7;
    for(int i=2;i<=maxi;i++){
        an[i] = 4LL*an[i-1]+bn[i-1];
        bn[i] = an[i-1]+2LL*bn[i-1];
        an[i]%=mod;
        bn[i]%=mod;
    } 
    for(int i=0;i<n;i++){
        cout<<(an[a[i]]+bn[a[i]])%mod<<endl;
    }
 return 0;
}