//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#include <string>
// class Solution
// {
// 	public:
// 		vector<string> all_longest_common_subsequences(string s, string t)
// 		{   
// 		    int m =s.length();
// 		    int n = t.length();
// 		    vector<vector<string>> ans(m+1,vector<string>(n+1,""));
// 		    for(int i=0;i<=m;i++){
// 		        for(int j=0;j<=n;j++){
// 		            ans[i][j] = "";
// 		        }
// 		    }
// 		    int maxm = 0;
// 		    for(int i=1;i<=m;i++){
// 		        for(int j=1;j<=n;j++){
// 		            if(s[i-1]==t[j-1]){
// 		                ans[i][j]= ans[i-1][j-1]+s[i-1];
// 		            }else{
// 		                int k =ans[i][j-1].length();
// 		                int k1= ans[i-1][j].size();
// 		                if(k>k1) ans[i][j] = ans[i][j-1];
// 		                else ans[i][j] = ans[i-1][j];
// 		            }
// 		        }
// 		    }
// 		    return finalAns;
// 		}
// };

class Solution
{
	public:
		vector<string> all_longest_common_subsequences(string s, string t)
		{   
		    int m =s.length();
		    int n = t.length();
		    int ans[m+1][n+1];
		    for(int i=0;i<=m;i++){
		        for(int j=0;j<=n;j++){
		            if(i==0||j==0){
		                ans[i][j] = 0;
		                continue;
		            }
		            if(s[i-1]==t[j-1]) ans[i][j] = 1 + ans[i-1][j-1];
		            else ans[i][j] = max(ans[i-1][j],ans[i][j-1]);
		        }
		    }
		    int len = ans[m][n];
		    vector<pair<int,int>> index;
		    for(int i=len;i<=m;i++){
		        for(int j=len;j<=n;j++){
		            if(ans[i][j]==len) index.push_back({i,j});
		        }
		    }
		    int k = index.size();
		    vector<string> str(k);
		    for(int x=0;x<k;x++){
		        int i=index[x].first;
		        int j =index[x].second;
		        while(i>0&&j>0){
		          if(s[i-1]==t[j-1]){
                    str[x].push_back(s[i-1]);
                    i--;
                    j--;
                  }else{
                        if(ans[i-1][j]>ans[i][j-1]){
                              i--;
                         }else{
                              j--;                    
                         }
                   }
		        }
		        reverse(str[x].begin(),str[x].end());
		        cout<<str[x]<<" ";
		    }
		    return str;
		}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	string s, t;
    	cin >> s >> t;
    	Solution ob;
    	vector<string> ans = ob.all_longest_common_subsequences(s, t);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}


// } Driver Code Ends