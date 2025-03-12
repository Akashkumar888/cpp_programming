class Solution {
  public:
      int solve(int i, int n, vector<int>& val, vector<int>& wt, int W, vector<vector<int>>& dp) {
          if (i >= n) return 0;
          if (dp[i][W] != -1) return dp[i][W];
  
          int maxi = 0;
          if (wt[i] <= W)maxi = max(maxi, val[i] + solve(i + 1, n, val, wt, W - wt[i],dp));
          
          maxi = max(maxi, solve(i + 1, n, val, wt, W, dp));
  
          return dp[i][W] = maxi;
      }
  
      int knapsack(int W, vector<int>& val, vector<int>& wt) {
          int n = val.size();
          vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));
          return solve(0, n, val, wt, W, dp);
      }
  };
  