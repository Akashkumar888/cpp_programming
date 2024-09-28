
#include <iostream>
#include <vector>
using namespace std;

bool binarySearchGrid(const vector<vector<int>>& grid, int target) {
    int m = grid.size();
    if (m == 0) return false;
    int n = grid[0].size();

    int low = 0;
    int high = m* n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        int row=mid/n;
        int col=mid%n;
        int midElement = grid[row][col];

        if (midElement == target) {
            return true; // Target found
        } else if (midElement < target) {
            low = mid + 1; // Move to the right half
        } else {
            high = mid - 1; // Move to the left half
        }
    }

    return false; // Target not found
}

int main() {
    vector<vector<int>> grid = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 50}
    };

    int target = 34;

    if (binarySearchGrid(grid, target)) {
        cout << "Element found in the grid." << endl;
    } else {
        cout << "Element not found in the grid." << endl;
    }

    return 0;
}
