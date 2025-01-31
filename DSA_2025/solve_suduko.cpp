#include <vector>
using namespace std;

bool valid(int row, int col, int num, vector<vector<int>>& mat) {
    // Row check
    for (int j = 0; j < 9; j++) {
        if (mat[row][j] == num) return false;
    }
    // Column check
    for (int i = 0; i < 9; i++) {
        if (mat[i][col] == num) return false;
    }
    // Subgrid check
    int x = (row / 3) * 3, y = (col / 3) * 3;
    for (int i = x; i < x + 3; i++) {
        for (int j = y; j < y + 3; j++) {
            if (mat[i][j] == num) return false;
        }
    }
    return true;
}

bool backtrack(int i, int j, vector<vector<int>>& mat) {
    if (i == 9) return true; // Board solved
    if (j == 9) return backtrack(i + 1, 0, mat); // Move to next row
    if (mat[i][j] != 0) return backtrack(i, j + 1, mat); // Skip pre-filled cells

    for (int num = 1; num <= 9; num++) {
        if (valid(i, j, num, mat)) {
            mat[i][j] = num;
            if (backtrack(i, j + 1, mat)) return true; // Recursive call
            mat[i][j] = 0; // Backtrack if needed
        }
    }
    return false;
}

void solveSudoku(vector<vector<int>>& mat) {
    backtrack(0, 0, mat);
}
