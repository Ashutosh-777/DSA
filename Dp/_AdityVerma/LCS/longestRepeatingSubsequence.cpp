//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		int LongestRepeatingSubsequence(string s){
		    int m = s.size();
		    int ans[m+1][m+1];
		    for(int i=0;i<=m;i++){
		        for(int j=0;j<=m;j++){
		            if(i==0||j==0){
		                ans[i][j]=0;
		                continue;
		            }
		            if(s[i-1]==s[j-1]&&i!=j) ans[i][j] = 1 + ans[i-1][j-1];
		            else ans[i][j]= max(ans[i][j-1],ans[i-1][j]);
		        }
		    }
		    return ans[m][m];
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends