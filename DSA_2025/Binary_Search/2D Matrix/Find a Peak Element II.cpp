
// A peak element in a 2D grid is an element that is strictly greater than all of its adjacent neighbors to the left, right, top, and bottom.
// Given a 0-indexed m x n matrix mat where no two adjacent cells are equal, find any peak element mat[i][j] and return the length 2 array [i,j].
// You may assume that the entire matrix is surrounded by an outer perimeter with the value -1 in each cell.
// You must write an algorithm that runs in O(m log(n)) or O(n log(m)) time.

// leetcode 
class Solution {
public:
    // find row index of maximum element in a column
    int maxRow(int col, vector<vector<int>>& mat) {
        int n = mat.size();
        int idx = 0;
        for(int i = 1; i < n; i++) {
            if(mat[i][col] > mat[idx][col]) {
                idx = i;
            }
        }
        return idx;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int l = 0, r = m - 1;

        while(l <= r) {
            int mid = l + (r - l) / 2;

            int row = maxRow(mid, mat);

            int left  = (mid - 1 >= 0) ? mat[row][mid - 1] : -1;
            int right = (mid + 1 < m) ? mat[row][mid + 1] : -1;

            // peak condition
            if(mat[row][mid] > left && mat[row][mid] > right) {
                return {row, mid};
            }
            else if(right > mat[row][mid]) {
                l = mid + 1;   // move right
            }
            else {
                r = mid - 1;   // move left
            }
        }
        return {-1, -1};
    }
};


// An element is considered a peak if it is greater than or equal to its four immediate neighbors: top, bottom, left, and right. For corner and edge elements, any missing neighbors are treated as having a value of negative infinity.
// Note: A peak element is not necessarily the global maximum, it only needs to satisfy the condition relative to its adjacent elements. Multiple peak elements may exist, return any one of them.
// Note that the driver code will print true if you return the correct position of peak element, else it will print false.
// gfg 

class Solution {
public:
    int maxRow(int col, vector<vector<int>>& mat) {
        int n = mat.size();
        int idx = 0;
        for(int i = 1; i < n; i++) {
            if(mat[i][col] > mat[idx][col]) {
                idx = i;
            }
        }
        return idx;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int l = 0, r = m - 1;

        while(l <= r) {
            int mid = l + (r - l) / 2;
            int row = maxRow(mid, mat);

            int left  = (mid - 1 >= 0) ? mat[row][mid - 1] : INT_MIN;
            int right = (mid + 1 < m) ? mat[row][mid + 1] : INT_MIN;

            if(mat[row][mid] >= left && mat[row][mid] >= right) {
                return {row, mid};
            }
            else if(right > mat[row][mid]) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        return {-1, -1};
    }
};

