
int lis(vector<int>& arr) {
  int n = arr.size();
  vector<int> dp(n, 1);
  int lis = 1;

  for (int i = 0; i < n; i++) {
      for (int j = i - 1; j >= 0; j--) {
          if (arr[j] < arr[i]) {
              dp[i] = max(dp[i], dp[j] + 1);
          }
      }
      lis = max(lis, dp[i]);
  }
  return lis;
}
