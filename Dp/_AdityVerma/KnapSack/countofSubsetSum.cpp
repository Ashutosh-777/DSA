//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//#define mod 1000000007
// class Solution{
    
//     //recursive way to do the rpoblem
//     int solve(int arr[],int n,int sum,int **ans){
//         if(ans[n][sum]!=-1) return ans[n][sum];
//         //check for n==0&&sum==0
//         if(n==0){
//         if(sum==0) return ans[n][sum] = 1;
//             return ans[n][sum] = 0;
//         }
//         int a = 0;
//         if(arr[n-1]<=sum){
//             a=solve(arr,n-1,sum-arr[n-1],ans);
//         }
//         int b = solve(arr,n-1,sum,ans);
//         return ans[n][sum] = ((a%mod)+(b%mod))%mod;
//     }
// 	public:
// 	int perfectSum(int arr[], int n, int sum)
// 	{
// 	    int ** ans = new int *[n+1];
// 	    for(int i=0;i<=n;i++){
// 	        ans[i]= new int [sum+1];
// 	        for(int j=0;j<=sum;j++) ans[i][j] =-1;
// 	    }
// 	    return solve(arr,n,sum,ans);
// 	}
	  
// };
class Solution{

	public:
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        int dp[n+1][sum+1], mod=pow(10,9)+7;
        for(int i=0; i<n+1; i++)
            dp[i][0] = 1;
        for(int i=1; i<sum+1; i++)
            dp[0][i] = 0;
            
        for(int i=1; i<n+1; i++){
            for(int j=0; j<sum+1; j++){
                if(j >= arr[i-1])
                    dp[i][j] = (dp[i-1][j-arr[i-1]] + dp[i-1][j])%mod;
                else
                    dp[i][j] = dp[i-1][j]%mod;
            }
        }
        return dp[n][sum];
	}
	  
};


//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends