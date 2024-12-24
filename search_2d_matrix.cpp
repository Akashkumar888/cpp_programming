
#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>> &mat, int x) {
    int m = mat.size();
    int n = mat[0].size();
    int l = 0, r = m * n - 1;

    while (l <= r) {
        int mid = l + (r - l) / 2;
        int row = mid / n;
        int col = mid % n;

        if (mat[row][col] == x) 
            return true;
        else if (mat[row][col] < x) 
            l = mid + 1;
        else 
            r = mid - 1;
    }
    return false;
}

int main() {
    // Hardcoded matrix
    vector<vector<int>> mat = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };

    int x;
    cout << "Matrix:\n";
    for (auto row : mat) {
        for (auto val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    cout << "Enter the target value: ";
    cin >> x;

    if (searchMatrix(mat, x))
        cout << "Target found in the matrix!\n";
    else
        cout << "Target not found in the matrix.\n";

    return 0;
}
