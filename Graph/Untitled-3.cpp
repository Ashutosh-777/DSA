#include<iostream>
using namespace std;

// DP
int MinCost2(int**cost,int m,int n){
    int ans[m][n];
    
    ans[m-1][n-1] = cost[m-1][n-1];

    for(int i = m-2;i>=0;i--){
        ans[i][n-1] = ans[i+1][n-1] + cost[i][n-1];
    }

    for(int i = n-2;i>=0;i--){
        ans[m-1][i] = ans[m-1][i+1] + cost[m-1][i];
    }

    for(int i = m-2;i>=0;i--){
        for(int j = n-2;j>=0;j--){
            ans[i][j] = min(ans[i+1][j+1],min(ans[i][j+1],ans[i+1][j])) + cost[i][j];
        }
    }

    
    return ans[0][0];
}


int main(){
    int **arr, n, m;
    cin >> n >> m;
    arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[m];
    }
    vector<vector<int>> graph = {
        {0, 9, 7, 3, 2, 0, 0, 0, 0, 0, 0, 0},
        {9, 0, 0, 0, 0, 4, 2, 1, 0, 0, 0, 0},
        {7, 0, 0, 0, 0, 2, 7, 0, 0, 0, 0, 0},
        {3, 0, 0, 0, 0, 0, 0, 11, 0, 0, 0, 0},
        {2, 0, 0, 0, 0, 0, 11, 8, 0, 0, 0, 0},
        {0, 4, 2, 0, 0, 0, 0, 0, 6, 5, 0, 0},
        {0, 2, 7, 0, 11, 0, 0, 0, 4, 3, 0, 0},
        {0, 1, 0, 11, 8, 0, 0, 0, 0, 5, 6, 0},
        {0, 0, 0, 0, 0, 6, 4, 0, 0, 0, 0, 4},
        {0, 0, 0, 0, 0, 5, 3, 5, 0, 0, 0, 2},
        {0, 0, 0, 0, 0, 0, 0, 6, 0, 0, 0, 6},
        {0, 0, 0, 0, 0, 0, 0, 0, 4, 2, 6, 0},
    };
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cin >> arr[i][j];
    //     }
    // }
    cout << MinCost2(arr, n, m) << endl;

}