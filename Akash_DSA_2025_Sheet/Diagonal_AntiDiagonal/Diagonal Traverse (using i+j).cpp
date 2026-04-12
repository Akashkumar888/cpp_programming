#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m; // matrix size n x m
    vector<vector<int>> mat(n, vector<int>(m));

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin >> mat[i][j];

    map<int, vector<int>> mp; // key = i+j
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            mp[i+j].push_back(mat[i][j]);
        }
    }

    cout << "Diagonal Traverse (i+j):\n";
    for(auto &p: mp){
        for(int x: p.second) cout << x << " ";
        cout << "\n";
    }
}

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int m = mat.size();
    int n = mat[0].size();

    // Upper diagonals (including main)
    for (int col = 0; col < n; col++) {
        int i = 0, j = col;
        while (i < m && j < n) {
            cout << mat[i][j] << " ";
            i++; j++;
        }
        cout << endl;
    }

    // Lower diagonals
    for (int row = 1; row < m; row++) {
        int i = row, j = 0;
        while (i < m && j < n) {
            cout << mat[i][j] << " ";
            i++; j++;
        }
        cout << endl;
    }
}
