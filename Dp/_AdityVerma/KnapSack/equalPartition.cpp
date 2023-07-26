//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
        bool isSubsetSum(int arr[], int sum,int n){
        //int n = arr.size();
        bool ans[n+1][sum+1];
        for(int i=0;i<n;i++){
            for(int j=0;j<=sum;j++){
                if(i==0){
                    ans[i][j]=false;
                }
                if(j==0){
                    ans[i][j]=true;
                }
            }
        }
        //corresponds to n-1
        for(int  i =1;i<=n;i++){
            //corrseponds to sum-1
            for(int j=1;j<=sum;j++){
                if(arr[i-1]<=j){
                    ans[i][j]=ans[i-1][j-arr[i-1]]||ans[i-1][j];
                }else{
                    ans[i][j]=ans[i-1][j];
                }
            }
        }
        return ans[n][sum];
    }
public:
    int equalPartition(int n, int arr[])
    {
        int sum = 0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        if(sum%2==1) return 0;
        else return isSubsetSum(arr,sum/2,n);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends