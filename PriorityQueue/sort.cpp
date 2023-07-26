#include <bits/stdc++.h>
using namespace std;
#include "maxHeap.h"
int main(){
    MaxHeap pq;
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        pq.insert(a[i]);
    }
    for(int i=0;i<n;i++){
        a[i]=pq.getMax();
        pq.pop();
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
 return 0;
}