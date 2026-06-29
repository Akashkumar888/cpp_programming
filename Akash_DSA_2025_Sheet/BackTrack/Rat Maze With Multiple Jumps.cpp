
class Solution {
  public:
    bool solve(int i, int j, int n,vector<vector<int>>& mat,vector<vector<int>>& path,vector<vector<int>>& dp) {
        if(i < 0 || i >= n || j < 0 || j >= n || mat[i][j] == 0) return false;

        if(i == n - 1 && j == n - 1) {
            path[i][j] = 1;
            return true;
        }

        if(dp[i][j] != -1) return dp[i][j];

        path[i][j] = 1;

        int jump = mat[i][j];

        for(int step = 1; step <= jump; step++) {
            // right first
            if(solve(i, j + step, n, mat, path, dp)) {
                return dp[i][j] = 1;
            }

            // then down
            if(solve(i + step, j, n, mat, path, dp)) {
                return dp[i][j] = 1;
            }
        }

        path[i][j] = 0;

        return dp[i][j] = 0;
    }
    vector<vector<int>> shortestDist(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<vector<int>> path(n, vector<int>(n, 0));
        vector<vector<int>> dp(n, vector<int>(n, -1));
        if(solve(0, 0, n, mat, path, dp)) {
            return path;
        }
        return {{-1}};
    }
};