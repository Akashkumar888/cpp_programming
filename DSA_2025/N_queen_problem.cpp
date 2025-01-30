
#include <bits/stdc++.h>
using namespace std;

bool valid(int row, int col, vector<vector<char>> &queen) {
    // Column check (upwards)
    for (int i = row - 1; i >= 0; i--) {
        if (queen[i][col] == 'Q') return false;
    }

    // Diagonal check (↖ up-left)
    int i = row - 1, j = col - 1;
    while (i >= 0 && j >= 0) {
        if (queen[i][j] == 'Q') return false;
        i--, j--;
    }

    // Anti-diagonal check (↗ up-right)
    i = row - 1, j = col + 1;
    while (i >= 0 && j < queen.size()) {
        if (queen[i][j] == 'Q') return false;
        i--, j++;
    }

    return true;
}

void backtrack(int i, int n, vector<int> &temp, vector<vector<char>> &queen, vector<vector<int>> &ans) {
    if (i == n) {  // Base case: All queens placed
        ans.push_back(temp);
        return;
    }

    for (int j = 0; j < n; j++) {
        if (valid(i, j, queen)) {
            queen[i][j] = 'Q';  // Place Queen
            temp.push_back(j + 1);  // Store 1-based column index
            backtrack(i + 1, n, temp, queen, ans);
            queen[i][j] = '.';  // Remove Queen (backtracking)
            temp.pop_back();
        }
    }
}

vector<vector<int>> nQueen(int n) {
    vector<vector<char>> queen(n, vector<char>(n, '.'));
    vector<vector<int>> ans;
    vector<int> temp;
    backtrack(0, n, temp, queen, ans);
    return ans;
}

int main() {
    int n = 4;  // Change this for different board sizes
    vector<vector<int>> solutions = nQueen(n);

    cout << "Total solutions: " << solutions.size() << endl;
    for (const auto &sol : solutions) {
        for (int pos : sol) {
            cout << pos << " ";
        }
        cout << endl;
    }

    return 0;
}
