#include<bits/stdc++.h> 
using namespace std; 
    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
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

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        cout << isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

