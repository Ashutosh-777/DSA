#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int idx = 0;
        while(a[idx]<=0){
            idx++;
        }
        if(idx==n){
            int x = *max_element(a,a+n);
            cout<<x<<endl;
            continue;
        }
        int sum = a[idx];
        int ans = sum;
        for(int i=idx+1;i<n;i++){
            sum+=a[i];
            if(abs(a[i])%2==abs(a[i-1])%2){
                // cout<<"i "<<i<<" ";
                 sum=a[i];}
                //  cout<<"SUm "<<sum<<endl;
            ans = max(sum,ans);
            if(sum<0) sum=0;
        }
        // cout<<-99%2<<endl;
        cout<<ans<<endl;
    }
 return 0;
}