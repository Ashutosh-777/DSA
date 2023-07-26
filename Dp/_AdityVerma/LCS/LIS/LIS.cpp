#include <bits/stdc++.h> 

// memoization implementation ...
int longIncrSubseq(vector<int> &arr, int i, int prevI, vector<vector<int>> &dp) {
    int n = arr.size() ;
    if(i == n) return 0 ;
    if(dp[i][prevI+1] != -1) return dp[i][prevI+1] ; 
    int len = 0 + longIncrSubseq(arr, i+1, prevI, dp) ;
    if(prevI == -1 || arr[i] > arr[prevI]) 
    len = max(len, 1 + longIncrSubseq(arr, i+1, i, dp)) ;
    return dp[i][prevI+1] = len ;
}

// Tabulation Implementation ...
int longIncrSubseq(vector<int> &arr) {
    int n = arr.size() ;
    vector<vector<int>> dp(n+1, vector<int>(n+2, 0)) ;
    for(int i=n-1; i>=0; i--) {
        for(int j=i-1; j>=-1; j--) {
            dp[i][j+1] = 0 + dp[i+1][j+1] ;
            if(j == -1 || arr[i] > arr[j]) dp[i][j+1] = max(dp[i][j+1], 1 + dp[i+1][i+1]) ;
        }
    }
    return dp[0][-1+1] ;
}

// space optimisation .. 
int longIncrSubseqS(vector<int> &arr) {
    int n = arr.size() ; int maxi = 0 ;
    vector<int> dp(n, 1) ;
    for(int i=0; i<n; i++) {
        for(int prev=0; prev<i; prev++) {
            if(arr[prev] < arr[i]) dp[i] = max(1+dp[prev], dp[i]) ;
        }
        maxi = max(maxi, dp[i]) ;
    }
    return maxi ;
}

int LIS(vector<int> &arr, int n){	
	// Write your code here.	
    // vector<vector<int>> dp(n, vector<int>(n+1, -1)) ;
    return longIncrSubseqS(arr) ;
}
