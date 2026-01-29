
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();    // Number of rows
        int n = mat[0].size(); // Number of columns

        // Map to store the value-to-coordinates mapping
        map<int, pair<int, int>> mp;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                mp[mat[i][j]] = {i, j}; // Map value to its coordinates
            }
        }

        // Arrays to track painted counts for rows and columns
        vector<int> row_count(m, 0);
        vector<int> col_count(n, 0);

        // Iterate through the array
        for (int i = 0; i < arr.size(); i++) {
            int val = arr[i];
            auto [row, col] = mp[val]; // Get the row and column of the current value

            // Increment row and column counts
            row_count[row]++;
            col_count[col]++;

            // Check if the row or column is completely painted
            if (row_count[row] == n || col_count[col] == m) {
                return i; // Return the first index where a row or column becomes complete
            }
        }

        return -1; // Return -1 if no row or column is completed
    }
};

// For testing purposes (remove this before submitting if not needed)
int main() {
    Solution sol;
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6}
    };
    cout << sol.firstCompleteIndex(arr, mat) << endl;  // Expected output: 2
    return 0;
}
