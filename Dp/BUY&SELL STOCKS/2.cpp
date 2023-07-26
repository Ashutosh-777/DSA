// int getMaximumProfit(int *arr, int n) {

//     int  mi=arr[0],mx=0;
//     for(int i=0;i<n;i++){
//         if(arr[i]<mi)mi=arr[i];
//         if (arr[i] > mi) {
//           mx += arr[i] - mi;
//           mi=arr[i];
//         }
//     }
//     return mx;
// }


// long solve(int i,int buy,long * values,int n,long **ans){
//     long profit=0;
//     if(i==n) return  0;
//     if(ans[i][buy]!=-1) return ans[i][buy];
//     if(buy){
//         profit= max(solve(i+1,0,values,n,ans)-values[i],solve(i+1,1,values,n,ans));
//     }else profit= max(values[i]+solve(i+1,1,values,n,ans),solve(i+1,0,values,n,ans));
//     return ans[i][buy]=profit;
// }
// long getMaximumProfit(long *values, int n)
// {
//     long **ans=new long *[n];
//     for(int i=0;i<n;i++){
//         ans[i]=new long [2];
//         for(int j=0;j<2;j++){
//             ans[i][j]=-1;
//         }
//     }

//     return solve(0,1,values,n,ans);
    
// }

#include <bits/stdc++.h>
long getMaximumProfit(long *values, int n)
{
   vector<long> ahead(2,0),curr(2,0);
   ahead[0]=0;
   ahead[1]=0;
   for(int i=n-1;i>=0;i--){
       for(int buy =0;buy<=1;buy++){
           long profit=0;
           if(buy){
               profit = max(values[i]+ahead[0],ahead[1]);
           }else profit = max(-values[i]+ahead[1],ahead[0]);
           curr[buy] = profit;
       }
       ahead=curr;
   }
   return curr[0];
}