
class Solution {
  public:
      int solve(int i, int n, vector<int>& cost, vector<int>& dp) {
          if (i >= n) return 0; // Base case: reached top
          if (dp[i] != -1) return dp[i]; // If already computed, return stored value
  
          // Take either 1 step or 2 steps and calculate the minimum cost
          int mini = INT_MAX;
          mini = min(mini, cost[i] + solve(i + 1, n, cost, dp));
          mini = min(mini, cost[i] + solve(i + 2, n, cost, dp));
  
          return dp[i] = mini; // Store result in dp array
      }
  
      int minCostClimbingStairs(vector<int>& cost) {
          int n = cost.size();
          vector<int> dp1(n + 1, -1), dp2(n + 1, -1);
  
          // Compute minimum cost starting from step 0 and step 1
          int startZeroIndex = solve(0, n, cost, dp1);
          int startOneIndex = solve(1, n, cost, dp2);
  
          return min(startZeroIndex, startOneIndex);
      }
  };
  