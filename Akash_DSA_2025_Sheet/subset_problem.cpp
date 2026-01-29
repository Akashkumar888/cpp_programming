
bool solve(int i, int n, vector<int>& arr, int sum, vector<vector<int>>& dp) {
  if (i == n - 1) return sum == arr[i];
  if (arr[i] == sum) return true;
  if (dp[i][sum] != -1) return dp[i][sum];

  bool pick = false;
  if (arr[i] <= sum)
      pick = solve(i + 1, n, arr, sum - arr[i], dp);

  bool notPick = solve(i + 1, n, arr, sum, dp);

  return dp[i][sum] = (pick || notPick);
}

bool isSubsetSum(vector<int>& arr, int sum) {
  int n = arr.size();
  vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
  return solve(0, n, arr, sum, dp);
}

