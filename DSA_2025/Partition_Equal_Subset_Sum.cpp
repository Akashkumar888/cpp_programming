
int solve(int i, int n, vector<int>& arr, int Sum, vector<vector<int>>& dp) {
  if (i == n - 1) {
      return Sum == arr[i];
  }
  if (arr[i] == Sum) return true;
  if (dp[i][Sum] != -1) return dp[i][Sum];
  
  bool pick = false;
  if (arr[i] <= Sum) pick = solve(i + 1, n, arr, Sum - arr[i], dp);
  
  bool notpick = solve(i + 1, n, arr, Sum, dp);
  
  return dp[i][Sum] = (pick || notpick);
}

bool equalPartition(vector<int>& arr) {
  int n = arr.size();
  int TotalSum = accumulate(arr.begin(), arr.end(), 0);
  if (TotalSum % 2) return false;
  
  int Sum = TotalSum / 2;
  vector<vector<int>> dp(n + 1, vector<int>(Sum + 1, -1));
  
  return solve(0, n, arr, Sum, dp);
}
