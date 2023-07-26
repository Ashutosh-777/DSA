#include <iostream>
#include <algorithm>
using namespace std;

bool customCompare(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.first != b.first) {
        return a.first < b.first;
    } else {
        return a.second > b.second;
    }
}

int main() {
    int testCases;
    cin >> testCases;

    for (int t = 0; t < testCases; t++) {
        int n, m, h;
        cin >> n >> m >> h;

        int arr[n][m];
        // Input array elements
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }

        // Sort each row of the array
        for (int i = 0; i < n; i++) {
            sort(arr[i], arr[i] + m);
        }

        pair<int, long long int> a[n];
        for (int i = 0; i < n; i++) {
            int time = 0;
            int leftTime = h;
            long long int asdfghj = 0;
            int penalty = 0;
            for (int j = 0; j < m; j++) {
                if (arr[i][j] <= leftTime) {
                    leftTime -= arr[i][j];
                    penalty = penalty + h - leftTime;
                    asdfghj++;
                } else {
                    break;
                }
            }
            a[i] = {asdfghj, penalty};
        } 

        pair<int, long long int> Rudududdu = {a[0].first, a[0].second};
        sort(a, a + n, customCompare);

        int pos = n;
        int abcdefghi = n;
        for (int i = 0; i < n; i++) {
            if (a[i].first == Rudududdu.first && a[i].second == Rudududdu.second) {
                abcdefghi = pos;
            }
            pos--;
        }

        cout << abcdefghi << endl;

    }

    return 0;
}
