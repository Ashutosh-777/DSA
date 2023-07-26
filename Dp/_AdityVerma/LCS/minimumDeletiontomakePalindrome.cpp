//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int minDeletions(string str, int n);

int main(){
    int t;
    cin >> t;
    while(t--){
        
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << minDeletions(s, n) << endl;

    }
return 0;
}
// } Driver Code Ends


int minDeletions(string t, int n) { 
    string s = t;
    reverse(t.begin(),t.end());
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
    return n-ans[n][n];
} 