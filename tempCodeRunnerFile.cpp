#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Sample vector of vectors
    std::vector<std::vector<int>> vecOfVecs = {
        {3, 1, 4},
        {1, 5, 9},
        {2, 6, 5},
        {3, 5, 8},
        {2, 7, 1}
    };

    // Sort the vector of vectors
    std::sort(vecOfVecs.begin(), vecOfVecs.end());

    // Output the sorted vector of vectors
    for (const auto& vec : vecOfVecs) {
        for (int num : vec) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
