bool wordBreak(string s, vector<string>& dictionary) {
  int n = s.size();
  vector<int> dp(n + 1, 0);
  dp[0] = 1;

  for (int i = 1; i <= n; i++) {
      for (auto &word : dictionary) {
          int start = i - word.size();
          if (start >= 0 && dp[start] && s.substr(start, word.size()) == word) {
              dp[i] = 1;
              break;
          }
      }
  }
  return dp[n];
}
