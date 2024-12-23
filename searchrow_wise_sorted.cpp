
#include <iostream>
#include <vector>
using namespace std;

// Function to search for the target in a row-wise sorted matrix
bool searchRowMatrix(vector<vector<int>> &mat, int x) {
    int m = mat.size();
    for (int i = 0; i < m; i++) {
        int l = 0, r = mat[i].size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (mat[i][mid] == x)
                return true;
            else if (mat[i][mid] < x)
                l = mid + 1;
            else
                r = mid - 1;
        }
    }
    return false;
}

int main() {
    // Given matrix (already initialized)
    vector<vector<int>> mat = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };

    // Target value to search for
    int x;
    cout << "Enter the target value: ";
    cin >> x;

    // Search for the target in the matrix
    if (searchRowMatrix(mat, x)) {
        cout << "Target " << x << " is present in the matrix." << endl;
    } else {
        cout << "Target " << x << " is not present in the matrix." << endl;
    }

    return 0;
}
