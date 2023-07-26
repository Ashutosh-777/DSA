//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
    int findTargetSumWays(vector<int>& arr, int target) {
        int n=arr.size();
        int sum=0;
        for(auto it:arr) sum+=it;
        if(sum-target<0 || (sum+target)%2 || target+sum<0) return 0;
        if(target<-1*sum) return 0;
        int val=(sum+target)/2;
        vector<vector<int>> dp(n,vector<int>(val+1,0));
        if(arr[0] == 0) dp[0][0] =2;  
        else dp[0][0] = 1;  
        if(arr[0]!=0 && arr[0]<=val) dp[0][arr[0]] = 1; 
        for(int i=1;i<n;i++){
            for(int s=0;s<=val;s++){
                int take = 0;
                if(arr[i]<=s) take=dp[i-1][s-arr[i]];
                int notTake= dp[i-1][s];
                dp[i][s]=take+notTake;
            }
        }
        return dp[n-1][val];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>arr(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>arr[i];
        }
        int target;
        cin >> target;

        Solution ob;
        cout<<ob.findTargetSumWays(arr,target);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends