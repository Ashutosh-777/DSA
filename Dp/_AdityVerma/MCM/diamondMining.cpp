#include <bits/stdc++.h>
#define pb push_back
int solve(vector<int> &a,int i,int j,vector<vector<int>>& dp){
	if(dp[i][j]!=-1) return dp[i][j];
	if(i>j) return 0;
	int ans = INT_MIN;
	for(int k=i;k<=j;k++){
		int x = solve(a,i,k-1,dp);
		int b = solve(a,k+1,j,dp);
		
		int c = a[i-1]*a[k]*a[j+1];
		ans = max(ans,x+b+c);
	}
	return dp[i][j] = ans;
}
int maxCoins(vector<int>& a)
{
	a.pb(1);
	a.insert(a.begin(),1);
	int m =a.size();
	vector<vector<int>> dp(m+1,vector<int>(m+1,-1));
	return solve(a,1,a.size()-2,dp);
	// Write your code here.
}