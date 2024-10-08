//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

// class Solution {
//     long long int solve(long long int start,long long int end,vector<int> &arr){
//         if(start==end) return 1;
//         if(start>end) return 0;
//         int n = arr.size();
//         long long int ans =INT_MAX;
//         for(int i=0;i<n;i++){
//             long long int res = arr[i]*start;
//             long long int x =  solve(res,end,arr);
//             if(x!=0) ans= min(ans,x+1);
//         }
//         return ans;
//     }
//   public:
//     int minimumMultiplications(vector<int>& arr, int start, int end) {
//         return solve(start,end,arr)-1;
//     }
// };
class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
                // Create a queue for storing the numbers as a result of multiplication
        // of the numbers in the array and the start number.
        if(start==end) return 0;
        queue<pair<int, int>> q;
        q.push({start, 0});

        // Create a dist array to store the no. of multiplications to reach
        // a particular number from the start number.
        vector<int> dist(100000, 1e9);
        dist[start] = 0;
        int mod = 100000;
        // Multiply the start no. with each of numbers in the arr
        // until we get the end no.
        while (!q.empty())
        {
            int node = q.front().first;
            int steps = q.front().second;
            q.pop();

            for (auto it : arr)
            {
                int num = (it * node) % mod;

                // If the no. of multiplications are less than before
                // in order to reach a number, we update the dist array.
                if (steps + 1 < dist[num])
                {
                    dist[num] = steps + 1;

                    // Whenever we reach the end number
                    // return the calculated steps
                    if (num == end)
                        return steps + 1;
                    q.push({num, steps + 1});
                }
            }
        }
        // If the end no. is unattainable.
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends