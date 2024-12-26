
#include <iostream>
#include <vector>
using namespace std;

void setMatrixZeroes(vector<vector<int>> &mat) {
    int m = mat.size();  // Number of rows
    int n = mat[0].size();  // Number of columns

    // Vectors to mark rows and columns to be zeroed
    vector<bool> row(m, false);
    vector<bool> col(n, false);

    // Traverse the matrix and mark the rows and columns containing zeroes
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == 0) {
                row[i] = true;  // Mark the row
                col[j] = true;  // Mark the column
            }
        }
    }

    // Traverse the matrix again and set cells to zero based on the markers
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (row[i] || col[j]) {
                mat[i][j] = 0;  // Set the cell to zero
            }
        }
    }
}

// Function to print the matrix
void printMatrix(const vector<vector<int>> &mat) {
    for (const auto &row : mat) {
        for (int elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }
}

int main() {
    // Input matrix
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 0, 6},
        {7, 8, 9}
    };

    cout << "Original Matrix:" << endl;
    printMatrix(mat);

    // Apply the function
    setMatrixZeroes(mat);

    cout << "Matrix after applying setMatrixZeroes:" << endl;
    printMatrix(mat);

    return 0;
}
