#include <bits/stdc++.h>
using namespace std;
class Pair{
    public:
    int weight;
    int value;
};
//get the max value from func to get ans
// vector<Pair> func(int w[],int v[],int n,int maxCapacity){
//     if(n==0){
//         vector<Pair> ans;
//         Pair smallAns ;
//         smallAns.weight = 0;
//         smallAns.value = 0;
//         ans.push_back(smallAns);
//         return ans;
//     }
//     vector<Pair> smallAns = func(w+1,v+1,n-1,maxCapacity);
//     int size = smallAns.size();
//     for(int i=0;i<size;i++){
//         if(smallAns[i].weight + w[0]<=maxCapacity){
//             int a = smallAns[i].value + v[0];
//             int b = smallAns[i].weight+w[0];
//             smallAns.push_back({b,a});
//         }
//     }
//     if(w[0]<maxCapacity){
//         smallAns.push_back({w[0],v[0]});
//     }
//     return smallAns;
// }
// int func_rec(int w[],int v[],int n,int maxCapacity){
//     if(n==0||maxCapacity==0){
//         return 0;
//     }
//     if(w[0]>maxCapacity){
//         return func_rec(w+1,v+1,n-1,maxCapacity);
//     }else
//     return max(func_rec(w+1,v+1,n-1,maxCapacity),func_rec(w+1,v+1,n-1,maxCapacity-w[0])+v[0]);
// }
int func(int v[], int w[], int n, int maxWeight){
    //Base Condition
    if(n==0||maxWeight==0){
        return 0;
    }
    //choices and recursion call
    int a = -1;
    if(w[n-1]<=maxWeight){
        a = func(v,w,n-1,maxWeight-w[n-1])+v[n-1];
    }
    int b = func(v,w,n-1,maxWeight);
    return max(a,b);
}
int helper(int v[], int w[], int n, int maxWeight,int**ans){
    //Base Condition
    if(ans[n][maxWeight]!=-1){
        return ans[n][maxWeight];
    }
    if(n==0||maxWeight==0){
        ans[n][maxWeight]=0;
        return ans[n][maxWeight];
    }
    //choices and recursion call
    int a = -1;
    if(w[n-1]<=maxWeight){
        a = helper(v,w,n-1,maxWeight-w[n-1],ans)+v[n-1];
    }
    int b = helper(v,w,n-1,maxWeight,ans);
    ans[n][maxWeight]= max(a,b); 
    return ans[n][maxWeight];  
}
int memo(int v[], int w[], int n, int maxWeight){
    int **ans = new int *[n+1];
    for(int i=0;i<=n;i++){
        ans[i]=new int [maxWeight+1];
        for(int j=0;j<=maxWeight;j++){
            ans[i][j]=-1;
        }
    }
    return helper(v,w,n,maxWeight,ans);
}
int func_dp(int v[], int w[], int n, int maxWeight){
    int ans[n+1][maxWeight+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=maxWeight;j++){
            if(i==0||j==0){
                ans[i][j]=0;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=maxWeight;j++){
            if(w[i-1]<=j){
                ans[i][j]=max(ans[i-1][j-w[i-1]]+v[i-1],ans[i-1][j]);
            }else{
                ans[i][j]=ans[i-1][j];
            }
        }
    }
    return ans[n][maxWeight];
}

int main(){
    int n;
    cin>>n;
    int maxCapacity;
    cin>>maxCapacity;
    int w[n],v[n];
    for(int i=0;i<n;i++){
        cin>>w[i];
    }
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    cout<<func(v,w,n,maxCapacity);
    return 0;
}