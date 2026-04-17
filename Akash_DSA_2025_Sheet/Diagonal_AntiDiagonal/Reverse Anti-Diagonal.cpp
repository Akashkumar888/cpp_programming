#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<vector<int>> mat = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    int n = mat.size();

    for (int i = 0; i < n / 2; i++) {
        swap(mat[i][n - i - 1], mat[n - i - 1][i]);
    }

    // print
    for (auto &row : mat) {
        for (auto x : row) cout << x << " ";
        cout << endl;
    }
}
