//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int cutRod(int price[], int n) {
        int ans[n+1][n+1];
        int wt[n];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                ans[i][j]=0;
            }
        }
        for(int i=0;i<n;i++){
            wt[i]=i+1;
        }
        int maxWeight = n;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(wt[i-1]<=j){
                    ans[i][j]=max(ans[i][j-wt[i-1]]+price[i-1],ans[i-1][j]);
                }else{
                    ans[i][j]=ans[i-1][j];
                }
                //cout<<ans[i][j]<<" ";
            }
            //cout<<endl;
        }
        return ans[n][n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends