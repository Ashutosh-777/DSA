//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int minCoins(int coins[], int n, int sum) 
	{ 
	    int ans[n+1][sum+1];
	    for(int i=0;i<=n;i++){
	        for(int j=0;j<=sum;j++){
	            if(i==0) ans[i][j]= INT_MAX-1;
	            if(j==0&&i!=0) ans[i][j]=0;
	        }
	    }
	    //code with slight variation from knapsack
	    //here we need to initialise 2nd row as well
	    for(int j=1;j<=sum;j++){
	        if(j% coins[0]==0)
	        ans[1][j]=j/coins[0];
	        else ans[1][j] = INT_MAX-1;
	    }
	    for(int i=2;i<=n;i++){
	        for(int j=1;j<=sum;j++){
	            if(coins[i-1]<=j)
	            ans[i][j] = min(ans[i][j-coins[i-1]]+1,ans[i-1][j]);
	            else
	            ans[i][j]=ans[i-1][j];
	        }
	    }
	    return ans[n][sum]==INT_MAX-1 ? -1 : ans[n][sum];
	    
	} 
	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends