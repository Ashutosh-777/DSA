//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int minOperations(string s, string t) 
	{ 
	    int m = s.size();
	    int n = t.size();
	    int ans[m+1][n+1];
	    for(int i=0;i<=m;i++){
	        for(int j=0;j<=n;j++){
	            if(i==0||j==0) ans[i][j]=0;
	        }
	    }
	    for(int i=1;i<=m;i++){
	        for(int j=1;j<=n;j++){
	            if(s[i-1]==t[j-1]){
	                ans[i][j]=ans[i-1][j-1]+1;
	            }else ans[i][j]= max(ans[i][j-1],ans[i-1][j]);
	        }
	    }
	    return m+n-2*ans[m][n];
	    
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends