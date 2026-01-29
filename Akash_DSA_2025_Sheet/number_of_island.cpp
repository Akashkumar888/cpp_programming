

vector<vector<int>> directions = {
  {1, 0}, {0, 1}, {0, -1}, {-1, 0},
  {-1, -1}, {1, 1}, {-1, 1}, {1, -1}
};

void dfs(int i, int j, vector<vector<char>>& grid, int n, int m) {
  if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 'W') return;
  grid[i][j] = 'W'; // mark visited
  for (auto &dir : directions) {
      int new_i = i + dir[0];
      int new_j = j + dir[1];
      dfs(new_i, new_j, grid, n, m);
  }
}

int countIslands(vector<vector<char>>& grid) {
  int n = grid.size(), m = grid[0].size(), islands = 0;
  for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
          if (grid[i][j] == 'L') {
              dfs(i, j, grid, n, m);
              islands++;
          }
      }
  }
  return islands;
}
