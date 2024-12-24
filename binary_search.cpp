
#include <iostream>
#include <vector>
#include <algorithm> // for binary_search

using namespace std;

bool searchRowMatrix(vector<vector<int>> &mat, int x) {
    int m = mat.size();
    for (int i = 0; i < m; i++) {
        if (binary_search(mat[i].begin(), mat[i].end(), x)) 
            return true;
    }
    return false;
}

int main() {
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int x = 5;

    if (searchRowMatrix(mat, x)) 
        cout << x << " is found in the matrix.\n";
    else 
        cout << x << " is not found in the matrix.\n";

    return 0;
}
