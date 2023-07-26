//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int findMinInsertions(string s){
        string t = s;
        reverse(t.begin(),t.end());
        int n =s.size();
        int ans[n+1][n+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                if(i==0||j==0) {ans[i][j] = 0;continue;}
                if(s[i-1]==t[j-1]) ans[i][j] = 1 + ans[i-1][j-1];
                else ans[i][j] = max(ans[i-1][j],ans[i][j-1]);
            }
        }
        return n - ans[n][n];
    }
};

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.findMinInsertions(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends