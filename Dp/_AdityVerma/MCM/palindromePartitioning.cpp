//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    bool isPalindrome(string s, int i,int j){
    while(i<j){
        if(s[i]!=s[j]) return false;
        else{
            i++;
            j--;
        }
    }
    return true;
}
    int solve(string s,int i,int n,vector<int>&dp){
    if(dp[i]!=-1) return dp[i];
    if(i==n) return 0;
    int ans =INT_MAX;
    for(int j=i;j<n;j++){
        if(isPalindrome(s,i,j)){
            int x = 1 + solve(s,j+1,n,dp);
            ans = min(ans,x);
        }
    }
    return dp[i] = ans;
}
public:
    int palindromicPartition(string str)
    {
    vector<int> dp(str.size()+1,-1);
    return solve(str,0,str.size(),dp)-1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends