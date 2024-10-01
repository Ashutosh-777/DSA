#include <bits/stdc++.h>
using namespace std;
int solve(string s){
    int zeros =0,ones =0;
    int n =s.size();
    for (int i = 0; i <n; i++)
    {
       if(s[i]=='0') zeros++;
       else ones++;
    }
    for(int i=0;i<n;i++){
        if(s[i]=='0'&&ones>0){
            ones--;
        }else if(s[i]=='0'&&ones==0){
            return n-i;
        }
        if(s[i]=='1'&&zeros>0){
            zeros--;
        }else if(s[i]=='1'&&zeros==0){
            return n-i;
        }
    }
    return 0;
}
int main(){
    int t;
    cin>>t;
    while(t--){        
        string s;
        cin>>s;
        cout<<solve(s)<<endl;
    }
 return 0;
}