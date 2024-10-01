#include <bits/stdc++.h>
using namespace std;
int main(){
    long long t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        long long a[n];
        pair<long long,  long long>b[n];
        for(long long i=0;i<n;i++){
            cin>>a[i];
            b[i].first = a[i];
            b[i].second=i;
        }
        sort(b,b+n);
        long long pre[n];
        long long c[n];
        pre[0]=b[0].first;
        for(long long i=1;i<n;i++){
            pre[i]=b[i].first+pre[i-1];
        }
        c[b[n-1].second]=n-1;
        for(long long i=n-2;i>=0;i--){
            if(pre[i]>=b[i+1].first){
                c[b[i].second] = c[b[i+1].second];
            }else{
                c[b[i].second] = i;
            }
        }
        for(long long i=0;i<n;i++){
            cout<<b[i].first<<" ";
        }
        cout<<endl;
        for(long long i=0;i<n;i++){
            cout<<c[i]<<" ";
        }
        cout<<endl;
    }
 return 0;
}