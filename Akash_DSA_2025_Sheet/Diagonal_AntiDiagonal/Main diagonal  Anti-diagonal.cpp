
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n; // size of square matrix
    vector<vector<int>> mat(n, vector<int>(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];

    // Collect main diagonal (i == j)
    vector<int> mainDiag;
    for (int i = 0; i < n; i++)
        mainDiag.push_back(mat[i][i]);

    // Collect anti-diagonal (i + j == n - 1)
    vector<int> antiDiag;
    for (int i = 0; i < n; i++)
        antiDiag.push_back(mat[i][n - 1 - i]);

    // Sort both
    sort(mainDiag.begin(), mainDiag.end());
    sort(antiDiag.begin(), antiDiag.end());

    // Put them back
    for (int i = 0; i < n; i++)
        mat[i][i] = mainDiag[i];

    for (int i = 0; i < n; i++)
        mat[i][n - 1 - i] = antiDiag[i];

    // Print updated matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << mat[i][j] << " ";
        cout << "\n";
    }

    return 0;
}
