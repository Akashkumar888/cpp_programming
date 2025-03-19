
int solve(int i, int n, vector<int>& prices, int buy, int k, vector<vector<vector<int>>>& dp) {
  if (i == n) return 0;  // No days left
  if (k == 0) return 0;  // No transactions left
  
  if (dp[i][buy][k] != -1) return dp[i][buy][k];  // Memoization
  
  int profit = 0;
  
  if (buy) {
      int BuyIt = solve(i + 1, n, prices, 0, k, dp) - prices[i];
      int NotBuy = solve(i + 1, n, prices, 1, k, dp);
      profit = max(BuyIt, NotBuy);
  } else {
      int SellIt = solve(i + 1, n, prices, 1, k - 1, dp) + prices[i];
      int NotSell = solve(i + 1, n, prices, 0, k, dp);
      profit = max(SellIt, NotSell);
  }
  
  return dp[i][buy][k] = profit;
}

int maxProfit(vector<int>& prices) {
  int n = prices.size();
  int buy = 1;
  vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, -1)));
  return solve(0, n, prices, buy, 2, dp);  // Max 2 transactions allowed
}
