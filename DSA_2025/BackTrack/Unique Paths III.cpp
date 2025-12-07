class Solution {
public:
// Return the number of 4-directional walks from the starting square to the ending square, that walk over every non-obstacle square exactly once. 
// 0 representing empty squares we can walk over.
// -1 representing obstacles that we cannot walk over.
    // 4-direction moves
    int dx[4] = {1, 0, 0, -1};
    int dy[4] = {0, 1, -1, 0};

    int solve(int i, int j, int m, int n, int visitedCount, int totalCells,
              int end_i, int end_j, vector<vector<int>>& grid, vector<vector<bool>>& visited)
    {
        // out of bounds OR obstacle OR visited
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == -1 || visited[i][j])
            return 0;

        // reached ending cell
        if (i == end_i && j == end_j) {
            return (visitedCount == totalCells) ? 1 : 0;
        }

        // mark visited
        visited[i][j] = true;
        int path = 0;

        // try all four directions
        for (int k = 0; k < 4; k++) {
            int new_i = i + dx[k];
            int new_j = j + dy[k];
            path += solve(new_i, new_j, m, n, visitedCount + 1,
                          totalCells, end_i, end_j, grid, visited);
        }

        // unmark for backtracking
        visited[i][j] = false;

        return path;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        int startRow = 0, startCol = 0;
        int endRow = 0, endCol = 0;
        int totalCells = 0;

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        // count walkable cells + find start + find end
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] != -1)
                    totalCells++;  // count walkable

                if (grid[i][j] == 1) {
                    startRow = i;
                    startCol = j;
                }
                if (grid[i][j] == 2) {
                    endRow = i;
                    endCol = j;
                }
            }
        }
        // visitedCount initially = 1 (starting cell counts as visited)
        return solve(startRow, startCol, m, n, 1, totalCells,
                     endRow, endCol, grid, visited);
    }
};

class Solution {
public:
// Return the number of 4-directional walks from the starting square to the ending square, that walk over every non-obstacle square exactly once. 
// 0 representing empty squares we can walk over.
// -1 representing obstacles that we cannot walk over.
    // 4-direction moves
    int dx[4] = {1, 0, 0, -1};
    int dy[4] = {0, 1, -1, 0};
    int solve(int i, int j, int m, int n, int visitedCount, int totalCells,
              int end_i, int end_j, vector<vector<int>>& grid)
    {
        // out of bounds OR obstacle OR visited
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == -1)return 0;
        // reached ending cell
        if (i == end_i && j == end_j) {
            return (visitedCount == totalCells) ? 1 : 0;
        }
        // mark visited
        int temp=grid[i][j];
        grid[i][j]=-1;
        int path = 0;

        // try all four directions
        for (int k = 0; k < 4; k++) {
            int new_i = i + dx[k];
            int new_j = j + dy[k];
            path += solve(new_i, new_j, m, n, visitedCount + 1,
                          totalCells, end_i, end_j, grid);
        }
        // unmark for backtracking
        grid[i][j]=temp;
        return path;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int startRow = 0, startCol = 0;
        int endRow = 0, endCol = 0;
        int totalCells = 0;
        // count walkable cells + find start + find end
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != -1)
                    totalCells++;  // count walkable
                if (grid[i][j] == 1) {
                    startRow = i;
                    startCol = j;
                }
                if (grid[i][j] == 2) {
                    endRow = i;
                    endCol = j;
                }
            }
        }
        // visitedCount initially = 1 (starting cell counts as visited)
        return solve(startRow, startCol, m, n, 1, totalCells,
                     endRow, endCol, grid);
    }
};

