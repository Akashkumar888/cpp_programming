class Solution {
public:
    int dx[4] = {1, 0, 0, -1};
    int dy[4] = {0, 1, -1, 0};

    int f(int i, int j, int m, int n,int visitedCount, int totalCells,int end_i, int end_j,vector<vector<int>> grid,vector<vector<bool>> visited){
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == -1 || visited[i][j])       return 0;
        // if reached the ending cell
        if(i == end_i && j == end_j) {
            return (visitedCount == totalCells) ? 1 : 0;
        }
        visited[i][j] = true;
        int path = 0;
        for(int k = 0; k < 4; k++) {
            int new_i = i + dx[k];
            int new_j = j + dy[k];

            path += f(new_i, new_j, m, n,
                      visitedCount + 1, totalCells,
                      end_i, end_j,
                      grid, visited);
        }
        return path;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        pair<int,int> start;
        pair<int,int> end;
        int totalCells = 0;
        // find start, end and count all non-obstacle cells
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] != -1) totalCells++;

                if(grid[i][j] == 1) start = {i, j};
                else if(grid[i][j] == 2) end = {i, j};
            }
        }
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        // visitedCount = 1 because start cell is counted
        return f(start.first, start.second, m, n,1, totalCells,end.first, end.second,grid, visited);
    }
};

