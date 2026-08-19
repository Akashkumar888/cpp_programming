
class Solution {
  public:
    int MOD = 1e9 + 7;
    vector<int> solve(int i, int j, int n,vector<vector<int>>& grid,vector<vector<vector<int>>>& dp) {
        // Outside the matrix
        if(i >= n || j >= n) return {0, 0};

        // Destination
        if(i == n - 1 && j == n - 1) return {1, grid[i][j]};

        // Already calculated
        if(dp[i][j][0] != -1) return dp[i][j];

        int ways = 0;
        int maxSum = 0;

        // Move Right
        if(grid[i][j] == 1 || grid[i][j] == 3) {
            vector<int> right = solve(i, j + 1, n, grid, dp);
            ways = (ways + right[0]) % MOD;
            if(right[0] > 0) {
                maxSum = max(maxSum, grid[i][j] + right[1]);
            }
        }
        // Move Down
        if(grid[i][j] == 2 || grid[i][j] == 3) {
            vector<int> down = solve(i + 1, j, n, grid, dp);

            ways = (ways + down[0]) % MOD;

            if(down[0] > 0) {
                maxSum = max(maxSum, grid[i][j] + down[1]);
            }
        }
        return dp[i][j] = {ways, maxSum};
    }
    vector<int> findWays(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n, vector<int>(2, -1)));
        return solve(0, 0, n, grid, dp);
    }
};