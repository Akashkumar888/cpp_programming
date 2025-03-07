
int lis(int i, int j, string &s1, string &s2, vector<vector<int>> &dp) {
  if (i < 0 || j < 0) return 0;
  if (dp[i][j] != -1) return dp[i][j];
  if (s1[i] == s2[j]) return dp[i][j] = 1 + lis(i - 1, j - 1, s1, s2, dp);
  return dp[i][j] = max(lis(i - 1, j, s1, s2, dp), lis(i, j - 1, s1, s2, dp));
}

int longestPalinSubseq(string &s) {
  int n = s.size();
  string s2 = s;
  reverse(s2.begin(), s2.end());
  vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
  return lis(n - 1, n - 1, s, s2, dp);
}
