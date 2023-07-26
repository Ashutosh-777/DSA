#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    int b = prices[0];
    int n = prices.size();
    int profit = 0;
    for(int i=1;i<n;i++){
        int curr = prices[i];
        if(b<curr){
            profit = max(profit,curr-b);
        }else{
            b=prices[i];
        }
    }
    return profit;
}
