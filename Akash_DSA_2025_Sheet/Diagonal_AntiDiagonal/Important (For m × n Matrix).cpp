#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<vector<int>> mat = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12}
    };

    int m = mat.size();
    int n = mat[0].size();

    // store diagonal
    vector<int> diag;
    for (int i = 0; i < min(m, n); i++) {
        diag.push_back(mat[i][i]);
    }

    reverse(diag.begin(), diag.end());

    // put back
    for (int i = 0; i < min(m, n); i++) {
        mat[i][i] = diag[i];
    }

    // print
    for (auto &row : mat) {
        for (auto x : row) cout << x << " ";
        cout << endl;
    }
}
