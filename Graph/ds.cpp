#include <bits/stdc++.h>
using namespace std;
// class DisjointSet{
//     vector<int> parent;
//     public:
//     DisjointSet(int n){
//         parent.resize(n+1,-1);
//     }
//     int findUPar(int u){
//         if(parent[u]<0){
//             return u;
//         }else{
//             return findUPar(parent[u]);
//         }
//     }
//     //we can also detect cycle
//     //returns true if cycle is detected
//     void unionBySize(int u,int v){
//         int ulp_u = findUPar(u);
//         int ulp_v = findUPar(v);
//          if(ulp_u==ulp_v){
//             return;
//         }else{
//             int sz_u = abs(parent[ulp_u]);
//             int sz_v = abs(parent[ulp_v]);
//             if(sz_u>=sz_v){
//                 parent[ulp_u]+=parent[ulp_v];
//                 parent[v] = ulp_u;
//             }else{
//                 parent[ulp_v]+=parent[ulp_u];
//                 parent[u] = ulp_v;
//             }
//             return;
//         }
//     }
// };
//Abdul bari
//no need of another size array
// class DisjointSet{
//     vector<int> parent;
//     public:
//     DisjointSet(int n){
//         parent.resize(n+1,-1);
//     }
//     int findUPar(int u){
//         if(parent[u]<0){
//             return u;
//         }
//         return findUPar(parent[u]);
//     }
//     void unionBySize(int u,int v){
//         int ulp_u = findUPar(u);
//         int ulp_v = findUPar(v);
//         if(ulp_u==ulp_v){
//             return;
//         }else{
//             if(abs(parent[ulp_u])>=abs(parent[ulp_v])){
//                 parent[ulp_u]+=parent[ulp_v];
//                 parent[ulp_v] = ulp_u;
//             }else{
//                 parent[ulp_v]+=parent[ulp_u];
//                 parent[ulp_u]=ulp_v;
//             }
//         }
//     }
// };
class DisjointSet{
    vector<int> parent,rank,size;
    public:
    DisjointSet(int n){
        parent.resize(n+1);
        rank.resize(n+1,0);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++) parent[i]=i;
    }
    
    int findUPar(int u){
        if(parent[u]==u) return u;
        return parent[u] = findUPar(parent[u]);
    }

    void unionByRank(int u,int v){
        int pu = findUPar(u);
        int pv = findUPar(v);
        int pu_rank = rank[pu];
        int pv_rank = rank[pv];
        if(pu==pv){
            return;
        }
        if(pu_rank==pv_rank){
            rank[pu]++;
            parent[pv] = pu;
        }else if(pu_rank>pv_rank){
            parent[pv]=pu;
        }else{
            parent[pu]=pv;
        }
    }
    void unionBySize(int u,int v){
        int pu = findUPar(u);
        int pv = findUPar(v);
        if(pu==pv) return;
        if(size[pu]>=size[pv]){
            parent[pv] = pu;
            size[pu]+=size[pv];
        }else{
            parent[pu]=pv;
            size[pv]+=size[pu];
        }
    }
};
int main(){
    //         DisjointSet ds(7);
    // ds.unionBySize(1, 2);
    // ds.unionBySize(2, 3);
    // ds.unionBySize(4, 5);
    // ds.unionBySize(6, 7);
    // ds.unionBySize(5, 6);
    // // if 3 and 7 same or not
    // if (ds.findUPar(3) == ds.findUPar(7)) {
    //     cout << "Same\n";
    // }
    // else cout << "Not same\n";
    // //ds.unionByRank(3, 7);
    // cout<<ds.findUPar(3)<<" "<<ds.findUPar(7)<<endl;
    // if (ds.findUPar(4) == ds.findUPar(7)) {
    //     cout << "Same\n";
    // }
    // else cout << "Not same\n";
                DisjointSet ds(7);
    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);
    // if 3 and 7 same or not
    if (ds.findUPar(3) == ds.findUPar(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";
    //ds.unionByRank(3, 7);
    cout<<ds.findUPar(3)<<" "<<ds.findUPar(7)<<endl;
    if (ds.findUPar(4) == ds.findUPar(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";
 return 0;
}