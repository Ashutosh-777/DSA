//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
//Recursive code
// class Solution{
//     int solve(int n,int arr[],int i,int j){
//         if(i>=j) return 0;
//         int finalAns = INT_MAX;
//         for(int k=i;k<j;k++){
//             int temp = solve(n,arr,i,k) + solve(n,arr,k+1,j) + arr[i-1]*arr[k]*arr[j];
//             finalAns = min(temp,finalAns);
//         }
//         return finalAns;
//     }
// public:
//     int matrixMultiplication(int N, int arr[])
//     {
//         int ** ans = new int *[N];
//         return solve(N,arr,1,N-1);
//     }
// };
//int ans[101][101];
//Memoization__BottomUp
// class Solution{
//     int solve(int n,int arr[],int i,int j){
//         if(i>=j) return ans[i][j]=0;
//         int finalAns = INT_MAX;
//         for(int k=i;k<j;k++){
//             int temp = arr[i-1]*arr[k]*arr[j];
//             if(ans[i][k]==-1){
//                 temp+=solve(n,arr,i,k);
//             }else{
//                 temp+=ans[i][k];
//             }
//             if(ans[k+1][j]==-1){
//                 temp+=solve(n,arr,k+1,j);
//             }else{
//                 temp+=ans[k+1][j];
//             }
              
//             finalAns = min(temp,finalAns);
//         }
//         return ans[i][j]=finalAns;
//     }
// public:
//     int matrixMultiplication(int N, int arr[])
//     {
//         // int ** ans = new int *[N];
//         memset(ans,-1,sizeof(ans));
//         return solve(N,arr,1,N-1);
//     }
// };
//TOPDOWN

class Solution{
    int solve(int n,int p[]){
        
	/* For simplicity of the program, one
	extra row and one extra column are
	allocated in m[][]. 0th row and 0th
	column of m[][] are not used */
	int m[n][n];

	int i, j, k, L, q;

	/* m[i, j] = Minimum number of scalar
	multiplications needed to compute the
	matrix A[i]A[i+1]...A[j] = A[i..j] where
	dimension of A[i] is p[i-1] x p[i] */

	// cost is zero when multiplying
	// one matrix.
	for (i = 1; i < n; i++)
		m[i][i] = 0;

	// L is chain length.
	for (L = 2; L < n; L++)
	{
		for (i = 1; i < n - L + 1; i++)
		{
			j = i + L - 1;
			m[i][j] = INT_MAX;
			for (k = i; k <= j - 1; k++)
			{
				// q = cost/scalar multiplications
				q = m[i][k] + m[k + 1][j]
					+ p[i - 1] * p[k] * p[j];
				if (q < m[i][j])
					m[i][j] = q;
			}
		}
	}

	return m[1][n - 1];
    }
public:
    int matrixMultiplication(int N, int arr[])
    {
        // int ** ans = new int *[N];
        //memset(ans,-1,sizeof(ans));
        return solve(N,arr);
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
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends