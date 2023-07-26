#include <bits/stdc++.h>
#include <vector>

int main() {
    int m, n;
    cout << "Enter the number of rows: ";
    cin >> m;
    cout << "Enter the number of columns: ";
    cin >> n;

    // Create a 2D vector
    vector<vector<int>> grid(m, vector<int>(m));

    cout << "Enter the elements of the 2D vector:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j <n; j++) {
            cin >> grid[i][j];
        }
    }

    // Printing the 2D vector

    cout << "The 2D vector you entered:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j <n; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
