
class Solution {
  public:
      int solve(int i, int n, vector<int>& arr, vector<int>& dp) {
          if (i == n - 1) return 0;   // Reached last index
          if (arr[i] == 0) return 1e9; // Cannot move forward
          if (dp[i] != -1) return dp[i];
  
          int step = 1e9;
          for (int j = 1; j <= arr[i]; j++) {
              if (i + j < n) 
                  step = min(step, 1 + solve(i + j, n, arr, dp));
          }
          return dp[i] = step;
      }
  
      int minJumps(vector<int>& arr) {
          int n = arr.size();
          vector<int> dp(n + 1, -1);
          int val = solve(0, n, arr, dp);
          return (val == 1e9) ? -1 : val;
      }
  };
  