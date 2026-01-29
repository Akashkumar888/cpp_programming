
int solve(int i, int n, string &s, vector<int>& dp) {
  if (i >= n) {
      return 1; // Successfully decoded
  }
  if (s[i] == '0') return 0; // No mapping for '0'
  if (dp[i] != -1) return dp[i];

  int ways = 0;

  // Single digit
  ways += solve(i + 1, n, s, dp);

  // Double digit
  if (i + 1 < n) {
      int num = (s[i] - '0') * 10 + (s[i + 1] - '0');
      if (num >= 10 && num <= 26) {
          ways += solve(i + 2, n, s, dp);
      }
  }

  return dp[i] = ways;
}

int countWays(string &digits) {
  int n = digits.size();
  vector<int> dp(n + 1, -1);
  return solve(0, n, digits, dp);
}
