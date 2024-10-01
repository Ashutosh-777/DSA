#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int> v;
    for(int i=0;i<n;i++){
        if(v.size()==0||v.back()<a[i]) v.push_back(a[i]);
        else{
            int ind = lower_bound(v.begin(),v.end(),a[i])-v.begin();
            v[ind]=a[i];
        }
    }
    cout<<v.size()<<endl;
 return 0;
}