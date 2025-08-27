
#include <bits/stdc++.h>
using namespace std;

void diagonalTraverse(vector<vector<int>>& mat) {
    int n = mat.size();
    map<int, vector<int>> diag;  // key = i+j

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            diag[i + j].push_back(mat[i][j]);
        }
    }

    for (auto &p : diag) {
        for (int x : p.second) cout << x << " ";
    }
    cout << endl;
}

int main() {
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    diagonalTraverse(mat);
}
