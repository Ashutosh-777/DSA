#include <bits/stdc++.h>
using namespace std;
#define lli long long int
vector<int> rabin_karp(string const &s,string const &p){
    int m =s.size();
    int n =p.size();
    if(m<n) return {};
    const int mod = 1e9+7;
    const int multiplier = 31;
    lli hash_p = 0;
    vector<lli> hash_s(m+1,0),power(m);
    power[0] = 1;
    for(int i=1;i<m;i++){
        power[i] = (1LL*power[i-1]*multiplier)%mod;
    }
    for(int i=0;i<n;i++){
        hash_p = (hash_p + (p[i]-'a'+1)*power[i])%mod;
    }
    for(int i=0;i<m;i++){
        hash_s[i+1] = (hash_s[i] + (s[i]-'a'+1)*power[i])%mod;
    }
    vector<int> ans;
    for(int i=0;i<m-n+1;i++){
        lli curr_h = (hash_s[i+n]-hash_s[i] + mod )%mod;
        if(curr_h == (hash_p*power[i])%mod) ans.push_back(i);
    }
    return ans;
}
int main(){
    string s,p;
    cin>>s>>p;
    vector<int> occurances =rabin_karp(s,p); 
    cout<<"size: "<<occurances.size()<<endl;
    for(int ind:occurances){
        cout<<ind<<" ";
    }
 return 0;
}