
int solve(int i, int n, vector<int>& arr, vector<int>& dp) {
  if (i >= n) return 0;
  if (dp[i] != -1) return dp[i];
  
  int totalMoney = 0;
  totalMoney = max(totalMoney, arr[i] + solve(i + 2, n, arr, dp)); // Rob current house
  totalMoney = max(totalMoney, solve(i + 1, n, arr, dp));          // Skip current house
  
  return dp[i] = totalMoney;
}

int findMaxSum(vector<int>& arr) {
  int n = arr.size();
  vector<int> dp(n + 1, -1);
  return max(solve(0, n, arr, dp), solve(1, n, arr, dp));
}
