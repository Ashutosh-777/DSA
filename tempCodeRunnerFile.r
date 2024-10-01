#include <iostream> 
#include <algorithm> 
#include <cmath> 
using namespace std; 
 
long long countPositions(int x, int y, int z, long long k) { 
    long long maxPositions = 0; 
     
    for (long long a = 1; a * a * a <= k; ++a) { 
        if (k % a != 0) continue; 
        for (long long b = 1; a * b * b <= k; ++b) { 
            if ((k / a) % b != 0) continue; 
            long long c = k / (a * b); 
            if (a <= x && b <= y && c <= z) { 
                long long positions = (x - a + 1) * (y - b + 1) * (z - c + 1); 
                maxPositions = max(maxPositions, positions); 
            } 
            if (a <= x && c <= y && b <= z) { 
                long long positions = (x - a + 1) * (y - c + 1) * (z - b + 1); 
                maxPositions = max(maxPositions, positions); 
            } 
            if (b <= x && a <= y && c <= z) { 
                long long positions = (x - b + 1) * (y - a + 1) * (z - c + 1); 
                maxPositions = max(maxPositions, positions); 
            } 
            if (b <= x && c <= y && a <= z) { 
                long long positions = (x - b + 1) * (y - c + 1) * (z - a + 1); 
                maxPositions = max(maxPositions, positions); 
            } 
            if (c <= x && a <= y && b <= z) { 
                long long positions = (x - c + 1) * (y - a + 1) * (z - b + 1); 
                maxPositions = max(maxPositions, positions); 
            } 
            if (c <= x && b <= y && a <= z) { 
                long long positions = (x - c + 1) * (y - b + 1) * (z - a + 1); 
                maxPositions = max(maxPositions, positions); 
            } 
        } 
    } 
     
    return maxPositions; 
} 
 
int main() { 
    int t; 
    cin >> t; 
     
    while (t--) { 
        int x, y, z; 
        long long k; 
        cin >> x >> y >> z >> k; 
         
        cout << countPositions(x, y, z, k) << endl; 
    } 
     
    return 0; 
}