

// 👉 All elements below in the same column are also negative
// So you should count column-wise, not row-wise, from top-right.
// ✅ Correct Top-Right Approach (Fix)
// 🔧 Correct Logic
// If grid[row][col] < 0
// Then all elements below it in this column are negative
// Count them at once
// Move left

// Style 1: Start from Top-Right Corner
class Solution {
public:
// which is sorted in non-increasing order both row-wise and column-wise, return the number of negative numbers in grid.
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int row = 0, col = n - 1;
        int count = 0;
        while (row < m && col >= 0) {
            if (grid[row][col] < 0) {
                // all elements below this are negative
                // row-wise count negative elements.
                count += (m - row);
                col--;
            } 
            else row++;
        }
        return count;
    }
};


// Style 2: Start from Bottom-Left Corner
class Solution {
public:
// which is sorted in non-increasing order both row-wise and column-wise, return the number of negative numbers in grid.
    int countNegatives(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int count=0;
        int row=m-1,col=0;  
        while(row>=0 && col<n){
            int num=grid[row][col];
            if(num>=0){
                col++;
            }
            else{ // all elements to the RIGHT in this row are negative
                count+=(n-col);// col-wise count negative elements.
                row--;
            }
        }
        return count;
    }
};


// ✅ Style 2: Bottom-Left Corner (Correct)
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int row = m - 1, col = 0;
        int count = 0;

        while (row >= 0 && col < n) {
            if (grid[row][col] < 0) {
                // all elements to the RIGHT in this row are negative
                count += (n - col);
                row--;          // move up
            } else {
                col++;          // move right
            }
        }
        return count;
    }
};
