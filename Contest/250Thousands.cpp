#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        long long  prefixSum[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(i==0){
                prefixSum[i]=a[i];
            }else{
                prefixSum[i]= prefixSum[i-1]+a[i];
            }
        }
        long long ans = LLONG_MIN;
        for(int k=1;k<=n;k++){
            if(n%k) continue;
            long long max_weight = prefixSum[k-1];
            long long min_weight = prefixSum[k-1];
            for(int i=2*k-1;i<n;i+=k){
                max_weight = max(max_weight,prefixSum[i]-prefixSum[i-k]);
                min_weight = min(min_weight,prefixSum[i]-prefixSum[i-k]);
            }
            ans = max(ans,max_weight-min_weight);
        }
        cout<<ans<<endl;
    }
 return 0;
}