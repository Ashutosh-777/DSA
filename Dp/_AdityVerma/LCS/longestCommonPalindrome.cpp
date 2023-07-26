//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int longestPalinSubseq(string t) {
        string s = t;
        reverse(t.begin(),t.end());
        int n =s.size();
        int ans[n+1][n+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                if(i==0||j==0) ans[i][j]=0;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==t[j-1]) ans[i][j] = ans[i-1][j-1] + 1;
                else ans[i][j] =  max(ans[i][j-1],ans[i-1][j]);
            }
        }
        return ans[n][n];
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends