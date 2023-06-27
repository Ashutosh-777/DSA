//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    bool isSubsetSum(int arr[], int sum,int n,set<int>&v){
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
                // if(i==n&&ans[i][j]&&j<=sum/2){
                //     //m[j]=true;
                //     v.insert(j);
                // }
                if(i==n&&ans[i][j]){
                    v.insert(j);
                }
            }
        }
        return ans[n][sum];
    }

  public:
	int minDifference(int arr[], int n)  { 
	    //if(n==1){return arr[0];}
	    int sum=0;
	    for(int i=0;i<n;i++){
	        sum+=arr[i];
	    }
	    set<int> v;
	    vector<int> w;
	    int ans = isSubsetSum(arr,sum,n,v);
	    int min = INT_MAX;
	    for(auto it:v){
	       int a = sum-2*it;
	       a=abs(a);
	       if(min>a) min=a;
	    }
	    return min;
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends