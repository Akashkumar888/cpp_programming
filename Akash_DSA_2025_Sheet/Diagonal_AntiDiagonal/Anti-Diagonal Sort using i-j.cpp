
#include <bits/stdc++.h>
using namespace std;

void antiDiagonalSort(vector<vector<int>>& mat) {
    int n = mat.size();
    map<int, vector<int>> anti;

    // Collect
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            anti[i - j].push_back(mat[i][j]);
        }
    }

    // Sort
    for (auto &p : anti) {
        sort(p.second.begin(), p.second.end());
    }

    // Put back
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mat[i][j] = anti[i - j].back();
            anti[i - j].pop_back();
        }
    }
}

int main() {
    vector<vector<int>> mat = {
        {3, 2, 1},
        {6, 5, 4},
        {9, 8, 7}
    };
    antiDiagonalSort(mat);

    for (auto &row : mat) {
        for (int x : row) cout << x << " ";
        cout << endl;
    }
}

