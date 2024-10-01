#include <bits/stdc++.h>
using namespace std;
int main(){
    long long t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        long long a[n];
        bool flag = false;
        for(long i=0;i<n;i++){
            cin>>a[i];
            if(i>=1&&a[i]<a[i-1]){
                flag=true;
            }
        }
        if(flag){
            vector<long long> v;
            long long prev = a[0];
            for( long i=1;i<n;i++){
                if(a[i]<prev){
                    v.push_back(prev-a[i]);
                }else{
                    prev = a[i];
                }
            }
            sort(v.begin(),v.end());
            long long sz = v.size();
            long long ans = 0;
            long long prev2=0;
            for( long i=0;i<sz;i++){
                ans+=(sz+1-i)*(v[i]-prev2);
                prev2 = v[i];
            }
            cout<<ans<<endl;
        }else{
            cout<<0<<endl;
        }
    }
 return 0;
}