//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    //recursive Soln
    // int lcs(int x, int y, string s1, string s2)
    // {
    //     if(x==0||y==0) return 0;
    //     if(s1[x-1]==s2[y-1]) return lcs(x-1,y-1,s1,s2)+1;
    //     else return max(lcs(x-1,y,s1,s2),lcs(x,y-1,s1,s2));
    // }
    //MEMOIZATION
    // int helper(int x,int y,string s1,string s2,int** ans){
    //     if(ans[x][y]!=-1){
    //         return ans[x][y];
    //     }
    //     if(x==0||y==0){
    //         ans[x][y]=0;
    //         return ans[x][y];
    //     }
    //     if(s1[x-1]==s2[y-1]) {
    //         ans[x][y] = helper(x-1,y-1,s1,s2,ans)+1;
    //         return ans[x][y];
    //     }
    //     else {
    //         ans[x][y] =  max(helper(x-1,y,s1,s2,ans),helper(x,y-1,s1,s2,ans));
    //         return ans[x][y];
    //     }
    // }
    //  int lcs(int x, int y, string s1, string s2)
    // {
    //     int ** ans = new int *[x+1];
    //     for(int i=0;i<=x;i++){
    //         ans[i]= new int [y+1];
    //         for(int j=0;j<=y;j++){
    //             ans[i][j] = -1;
    //         }
    //     }
    //     return helper(x,y,s1,s2,ans);
    // }
    //DP SOLN
        int lcs(int x, int y, string s1, string s2)
    {
        int ans[x+1][y+1];
        for(int i=0;i<=x;i++){
            for(int j=0;j<=y;j++){
                if(i==0||j==0){
                    ans[i][j]=0;
                }
            }
        }
        for(int i=1;i<=x;i++){
            for(int j=1;j<=y;j++){
                if(s1[x-i]==s2[y-i]){
                    ans[i][j] = 1+ans[i-1][j-1];
                }else{
                    ans[i][j]=max(ans[i-1][j],ans[i][j-1]);
                }
            }
        }
        return ans[x][y];
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends