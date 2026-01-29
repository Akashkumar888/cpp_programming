
int solve(int i, int n, vector<int>& arr, vector<int>& dp) {
  if (i >= n) return 0;
  if (dp[i] != -1) return dp[i];
  int maxMoney = 0;
  maxMoney = max(maxMoney, arr[i] + solve(i + 2, n, arr, dp));
  maxMoney = max(maxMoney, solve(i + 1, n, arr, dp));
  return dp[i] = maxMoney;
}

int maxValue(vector<int>& arr) {
  int n = arr.size();
  if (n == 1) return arr[0]; // Edge case: Only one house
  vector<int> dp1(n, -1), dp2(n, -1);
  vector<int> arr1, arr2;
  
  // Case 1: Exclude last house
  for (int i = 0; i < n - 1; i++) arr1.push_back(arr[i]);
  
  // Case 2: Exclude first house
  for (int i = 1; i < n; i++) arr2.push_back(arr[i]);
  
  int stolenZeroth = solve(0, arr1.size(), arr1, dp1);
  int stolenFirst = solve(0, arr2.size(), arr2, dp2);
  
  return max(stolenZeroth, stolenFirst);
}
