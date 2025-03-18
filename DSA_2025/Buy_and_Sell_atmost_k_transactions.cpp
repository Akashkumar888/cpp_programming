
int solve(int i, int n, vector<int>& prices, int buy, int k, vector<vector<vector<int>>>& dp) {
  if (i >= n) return 0;
  if (k == 0) return 0;
  if (dp[i][buy][k] != -1) return dp[i][buy][k];
  
  int profit = 0;
  
  if (buy == 1) {
      int BuyIt = solve(i + 1, n, prices, 0, k, dp) - prices[i];
      int NotBuy = solve(i + 1, n, prices, 1, k, dp);
      profit = max(BuyIt, NotBuy);
  } else {
      int NotSell = solve(i + 1, n, prices, 0, k, dp);
      int SellIt = solve(i + 1, n, prices, 1, k - 1, dp) + prices[i];
      profit = max(SellIt, NotSell);
  }
  
  return dp[i][buy][k] = profit;
}

int maxProfit(vector<int>& prices, int k) {
  int n = prices.size();
  vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k + 1, -1)));
  return solve(0, n, prices, 1, k, dp);
}
