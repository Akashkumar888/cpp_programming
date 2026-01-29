
int solve(int i, int j, vector<int>& arr, vector<vector<int>>& dp) {
  if (i == j) return 0;
  if (dp[i][j] != -1) return dp[i][j];

  int leastNumber = INT_MAX;
  for (int k = i; k <= j - 1; k++) {
      int step = (arr[i - 1] * arr[k] * arr[j]) + solve(i, k, arr, dp) + solve(k + 1, j, arr, dp);
      leastNumber = min(leastNumber, step);
  }
  return dp[i][j] = leastNumber;
}

int matrixMultiplication(vector<int>& arr) {
  int n = arr.size();
  vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
  return solve(1, n - 1, arr, dp);
}
