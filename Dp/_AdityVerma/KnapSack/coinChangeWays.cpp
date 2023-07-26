//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int count(int coins[], int n, int sum) {

        // code here.
        long long int ans[n+1][sum+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=sum;j++){
                if(i==0||j==0)
                ans[i][j]=0;
                if(j==0) ans[i][j]=1;
            }
        }
        //ans[0][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                if(coins[i-1]<=j){
                    ans[i][j]= ans[i][j-coins[i-1]]+ans[i-1][j];
                }else{
                    ans[i][j] = ans[i-1][j];
                }
                //cout<<ans[i][j]<<" ";
            }
            //cout<<endl;
        }
        // for(int i=0;i<=n;i++){
        //     for(int j=0;j<=n;j++){
        //         if(i==n&&j==n) cout<<"  hel";
        //         cout<<ans[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return ans[n][sum];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends