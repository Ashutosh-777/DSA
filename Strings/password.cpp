#include <bits/stdc++.h>
using namespace std;
string solve(string &s){
    int n =s.size();
    vector<int> z(n,0);
    int l=0,r=0;
    z[0] = n;
    for(int i=1;i<n;i++){
        if(i<r){
            z[i] = min(z[i-l],r-i);
        }
        while(i+z[i]<n&&s[z[i]]==s[i+z[i]]) z[i]++;
        if(i+z[i]>r){
            l=i;
            r = i+z[i];
        }
    }
    set<int> st;
    for(int i=1;i<n;i++){
        if(i+z[i]==n){
            if(st.lower_bound(z[i])!=st.end()){
                return s.substr(0,z[i]);
            }
        }
        st.insert(z[i]);
    }
    return "Just a legend";
}
int main(){
    string s;
    cin>>s;
    cout<<solve(s);
 return 0;
}