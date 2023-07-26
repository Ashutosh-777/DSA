#include <bits/stdc++.h>
using namespace std;
// void upHeapify(int parent,int childIndex){
//     swap(pq[parent],pq[childIndex]);
//     childIndex = parent ;
//     if(childIndex<=0) return;
//     parent = (childIndex-1)/2;
//     if(pq[parent]>pq[childIndex]){
//         upHeapify(parent,childIndex);
//     }
// }
int main(){
    int n;
    cin>>n;
    int pq[n];
    for(int i=0;i<n;i++){
        cin>>pq[i];
    }
    //satisfy heap preoperty
    for(int childIndex=1;childIndex<n;childIndex++){
        int parent = (childIndex-1)/2;
        while(childIndex>0){
        if(pq[childIndex]<pq[parent]){
            swap(pq[childIndex],pq[parent]);
            childIndex = parent ;
            parent = (childIndex-1)/2;
        }else{
            break;
        }
        }
    }
    //now need to get minimum in front
    int lastind  = n-1;
    for(lastind=n-1;lastind>0;lastind--){
        swap(pq[0],pq[lastind]);
        int parent = 0;
        int child1 = 2*parent+1;
        int child2 = 2*parent+2;
        while(parent<lastind){
            if()
        if(pq[child1]<pq[child2]){
            if(pq[parent]>pq[child1]){
                swap(pq[parent],pq[child1]);
                parent =child1;
            } else break;
        }else{
            if(pq[parent]>pq[child2]){
                swap(pq[parent],pq[child2]);
                parent = child2;
            }else break;
        }
        }
    }
    for(int i=0;i<n;i++){
        cout<<pq[i]<<' ';
    }
    cout<<endl;
 return 0;
}