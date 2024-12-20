
#include <iostream>
#include <vector>
using namespace std;

// Function to traverse a matrix spirally
vector<int> spirallyTraverse(vector<vector<int>> &mat) {
    vector<int> ans;
    int m = mat.size();    // Number of rows
    int n = mat[0].size(); // Number of columns

    int top = 0, left = 0;        // Initial boundaries
    int down = m - 1, right = n - 1;
    int dir = 0;                 // Direction: 0-right, 1-down, 2-left, 3-up

    while (left <= right && top <= down) {
        if (dir == 0) { // Traverse from left to right
            for (int j = left; j <= right; j++) {
                ans.push_back(mat[top][j]);
            }
            top++; // Move top boundary down
        } else if (dir == 1) { // Traverse from top to bottom
            for (int i = top; i <= down; i++) {
                ans.push_back(mat[i][right]);
            }
            right--; // Move right boundary left
        } else if (dir == 2) { // Traverse from right to left
            for (int j = right; j >= left; j--) {
                ans.push_back(mat[down][j]);
            }
            down--; // Move bottom boundary up
        } else if (dir == 3) { // Traverse from bottom to top
            for (int i = down; i >= top; i--) {
                ans.push_back(mat[i][left]);
            }
            left++; // Move left boundary right
        }
        dir = (dir + 1) % 4; // Update direction
    }

    return ans;
}

// Driver function to test the spirallyTraverse function
int main() {
    // Input matrix
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Call the function
    vector<int> result = spirallyTraverse(mat);

    // Output the result
    cout << "Spiral Order Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
