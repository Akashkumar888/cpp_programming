
#include <bits/stdc++.h>
using namespace std;

void rotateby90(vector<vector<int>> &mat) {
    int n = mat.size();

    // Step 1: Transpose the matrix
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            swap(mat[i][j], mat[j][i]);
        }
    }

    // Step 2: Reverse each column
    for (int j = 0; j < n; j++) {
        int l = 0, r = n - 1;
        while (l <= r) {
            swap(mat[l][j], mat[r][j]);
            l++, r--;
        }
    }
}

// Driver Code
int main() {
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    rotateby90(mat);

    cout << "Rotated Matrix:" << endl;
    for (const auto &row : mat) {
        for (const auto &val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
