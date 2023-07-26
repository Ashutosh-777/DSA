//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    //s --> pattern
    //t --> str
    // int solve(string s,string t){
    //     if(t.size()==0){
    //         if(s.size()==0) return 1;
    //         else if(s[0]=='*') return solve(s.substr(1),t);
    //         else return 0;
    //     }
    //     if(s.size()==0){
    //         return 0;
    //     }
    //     // if(s.size()==0||t.size()==0){
    //     //     return s.size()==t.size();
    //     // }
    //     if(s[0]==t[0]||s[0]=='?'){
    //         return solve(s.substr(1),t.substr(1));
    //     }else if(s[0]!='*'&&s[0]!=t[0]) return 0;
    //     bool ans  = 0;
    //     int k = t.size();
    //     //*-->empty
    //     ans |=solve(s.substr(1),t);
    //     //*-->t[0]
    //     ans |=solve(s.substr(1),t.substr(1));
    //     //8-->more thsn one char
    //     ans |=solve(s,t.substr(1));
    //     // for(int i=0;i<k;i++){
    //     //     if(ans) return ans;
    //     //     ans = ans || solve(s.substr(1),t.substr(i));
    //     // }
    //     return ans;
    // }
    int memo[201][201];
    int solve(string s,string t){
            if(memo[s.size()][t.size()]!=-1) return memo[s.size()][t.size()];
        if(t.size()==0){
            if(s.size()==0) return memo[s.size()][t.size()] = 1;
            else if(s[0]=='*') return memo[s.size()][t.size()]=solve(s.substr(1),t);
            else return memo[s.size()][t.size()]= 0;
        }
        if(s.size()==0){
            return memo[s.size()][t.size()]=0;
        }
        // if(s.size()==0||t.size()==0){
        //     return s.size()==t.size();
        // }
        if(s[0]==t[0]||s[0]=='?'){
            return memo[s.size()][t.size()]=solve(s.substr(1),t.substr(1));
        }else if(s[0]!='*'&&s[0]!=t[0]) return 0;
        bool ans  = 0;
        int k = t.size();
        //*-->empty
        ans |=solve(s.substr(1),t);
        //*-->t[0]
        ans |=solve(s.substr(1),t.substr(1));
        //8-->more thsn one char
        ans |=solve(s,t.substr(1));
        // for(int i=0;i<k;i++){
        //     if(ans) return ans;
        //     ans = ans || solve(s.substr(1),t.substr(i));
        // }
        return memo[s.size()][t.size()]=ans;
    }
  public:
/*You are required to complete this method*/
    int wildCard(string pattern,string str)
    {
        memset(memo,-1,sizeof(memo));
        return solve(pattern,str);
        // int m = pattern.size();
        // int n = str.size();
        // int ans[m+1][n+1];
        // for(int i=0;i<=m;i++){
        //     for(int j=0;j<=n;j++){
        //         if(i==0){
        //             ans[i][j]=0;
        //             continue;
        //         }
        //         if(j==0){
        //             if(i==0||pattern[i-1]=='*'){
        //                 ans[i][j]=1;
        //             }else{
        //                 ans[i][j]=0;
        //             }
        //             continue;
        //         }
        //         if(pattern[i-1]==str[j-1]||pattern[i-1]=='?') ans[i][j] =ans[i-1][j-1];
        //         else if(pattern[i-1]=='*'){
        //             ans[i][j] = ans[i-1][j]||(ans[i][j-1]||ans[i-1][j-1]);
        //         }else ans[i][j] = 0;
        //     }
        // }
        // for(int i=0;i<=m;i++){
        //     for(int j=0;j<=n;j++) cout<<ans[i][j]<<" ";
        //     cout<<endl;
        // }
        // return ans[m][n];
    }
};

//{ Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
           string pat,text;
           cin>>pat;
cin.ignore(numeric_limits<streamsize>::max(),'\n');
           cin>>text;
           Solution obj;
           cout<<obj.wildCard(pat,text)<<endl;
   }
}

// } Driver Code Ends