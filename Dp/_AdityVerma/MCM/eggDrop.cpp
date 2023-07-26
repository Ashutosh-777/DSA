//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    int ans[201][201];
    int solve(int e,int f){
        //memoization
        if(ans[e][f]!=-1) return ans[e][f];
        //Base Condition
        if(e==1) return f;
        if(f==0||f==1) return f;
        //recursive calls and smallCalculations
        int temp = INT_MAX;
        for(int k=1;k<=f;k++){
            //added 1 because 1 attmept already done
            int a =1+solve(e-1,k-1);
            int b =1+solve(e,f-k);
            temp = min(temp,max(a,b));
        }
        return ans[e][f] = temp;
    }
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int eggDrop(int n, int k) 
    {
        // your code here
        memset(ans,-1,sizeof(ans));
        return solve(n,k);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}

// } Driver Code Ends