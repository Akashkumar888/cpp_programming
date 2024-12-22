
#include <iostream>
#include <vector>
using namespace std;

// Function to search for an element in a row-column sorted matrix
bool matSearch(vector<vector<int>> &mat, int x) {
    int m = mat.size();
    int n = mat[0].size();
    int row = 0, col = n - 1;

    while (row < m && col >= 0) {
        if (mat[row][col] < x)
            row++;
        else if (mat[row][col] > x)
            col--;
        else
            return true;
    }
    return false;
}

int main() {
    // Predefined matrix
    vector<vector<int>> mat = {
        {1, 4, 7, 11},
        {2, 5, 8, 12},
        {3, 6, 9, 16},
        {10, 13, 14, 17}
    };

    // Print the matrix
    cout << "Matrix:" << endl;
    for (const auto &row : mat) {
        for (const auto &ele : row) {
            cout << ele << " ";
        }
        cout << endl;
    }

    // Element to search
    int x;
    cout << "Enter the element to search for: ";
    cin >> x;

    if (matSearch(mat, x))
        cout << x << " is present in the matrix." << endl;
    else
        cout << x << " is not present in the matrix." << endl;

    return 0;
}
