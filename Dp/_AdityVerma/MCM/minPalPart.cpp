//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++


//Recursive soln
// class Solution{
//     bool isPalindrome(string s,int k,int j){
//         string t=s;
//         reverse(t.begin()+k,t.begin()+j+1);
//         for(int i=k;i<=j+1;i++){
//             if(s[i]!=t[i]){
//                 return false;
//             }
//         }
//         return true;
//     }
//     int solve(string s,int i,int j){
//         if(i>=j||isPalindrome(s,i,j)){
//             return 0;
//         }
//         int finalAns=INT_MAX;
//         for(int k=i;k<j;k++){
//             int temp = solve(s,i,k) + solve(s,k+1,j) + 1;
//             finalAns = min(temp,finalAns);
//         }
//         return finalAns;
//     }
// public:
//     int palindromicPartition(string str)
//     {
//         return solve(str,0,str.length()-1);
//         // code here
//     }
// };
int ans[501][501];
int dp[501][501];
class Solution{

    void isPalindrome(string s)
{
 
    // Get the size of the string
    int n = s.size();
 
    // Initially mark every
    // position as false
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            dp[i][j] = false;
    }
 
    // For the length
    for (int j = 1; j <= n; j++) {
 
        // Iterate for every index with
        // length j
        for (int i = 0; i <= n - j; i++) {
 
            // If the length is less than 2
            if (j <= 2) {
 
                // If characters are equal
                if (s[i] == s[i + j - 1])
                    dp[i][i + j - 1] = true;
            }
 
            // Check for equal
            else if (s[i] == s[i + j - 1])
                dp[i][i + j - 1] = dp[i + 1][i + j - 2];
        }
    }
}
    int solve(string s,int i,int j){
        if(i>=j||dp[i][j]){
            return ans[i][j]= 0;
        }
        if(ans[i][j]!=-1) return ans[i][j];
        int finalAns=INT_MAX;
        for(int k=i;k<j;k++){
            int temp =  1;
            if(ans[i][k]==-1){
                ans[i][k] = solve(s,i,k);
            }
            temp+=ans[i][k];
            if(ans[k+1][j]==-1) {
                ans[k+1][j]=solve(s,k+1,j);
            }
          temp+=ans[k+1][j];
            finalAns = min(temp,finalAns);
        }
        return ans[i][j]=finalAns;
    }
public:
    int palindromicPartition(string str)
    {
        memset(ans,-1,sizeof(ans));
        memset(dp,0,sizeof(dp));
        isPalindrome(str);
        return solve(str,0,str.length()-1);
        // code here
    }
};
// class Solution{
// public:

//     bool Is_palindrome(string temp){
        
//         int i = 0 , j = temp.size()-1;
//         while(i<=j){
            
//             if(temp[i] != temp[j]) return false;
//             i++;
//             j--;
//         }
        
//         return true ;
//     }
    
    
//     int solve(int index , string str , vector<int>& dp){
        
//             if(index >= str.size()) return -1 ;
            
//             if(dp[index] != -1) return dp[index];
            
//             int ans = INT_MAX ;
//             for(int k=index ; k<str.size() ; k++){
                
//                         string temp = str.substr(index,k-index+1) ;
                    
//                         if(Is_palindrome(temp)){
                            
//                                 int temp = 1 + solve(k+1 , str , dp) ; 
                                
//                                 ans = min(ans , temp) ;
//                         }
                        
//             }
            
//             return dp[index] =  ans ;
//     }
    

//     int palindromicPartition(string str)
//     {
//         // code here
//         if(Is_palindrome(str)) return 0 ;
        
//         vector<int> dp(str.size()+1 , -1) ;
        
//         return solve(0 , str , dp) ;
//     }
// };


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