
class Solution {
  public:
    int solve(int digits, int sum, vector<vector<int>> &dp){
        if(sum < 0) return 0;
        if(digits == 0){
            if(sum == 0) return 1;
            return 0;
        }
        if(dp[digits][sum] != -1) return dp[digits][sum];
        int ways = 0;
        for(int digit = 0; digit <= 9; digit++){
            ways += solve(digits - 1, sum - digit, dp);
        }
        return dp[digits][sum] = ways;
    }
    int countWays(int n, int sum) {
        if(sum > 9 * n) return -1;
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
        int ans = 0;
        // First digit cannot be zero
        for(int digit = 1; digit <= 9; digit++){
            ans += solve(n - 1, sum - digit, dp);
        }
        if(ans == 0) return -1;
        return ans;
    }
};

// 1-9 = maxSum = 9
// 10-99 = maxSum = 18
// 100-999 = maxSum = 27
// 1000-9999 = maxSum = 36
// 10000-99999 = maxSum = 45
// 100000-999999 = maxSum = 54
// 1000000-9999999 = maxSum = 63
// 10000000-99999999 = maxSum = 72
// 100000000-999999999 = maxSum = 81


class Solution {
  public:
    int countWays(int n, int sum) {
        if(sum > 9 * n) return -1;
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
        dp[0][0] = 1;
        for(int digits = 1; digits <= n; digits++){
            for(int s = 0; s <= sum; s++){
                for(int digit = 0; digit <= 9; digit++){
                    if(s >= digit)
                        dp[digits][s] += dp[digits - 1][s - digit];
                }
            }
        }
        int ans = 0;

        // First digit cannot be zero
        for(int digit = 1; digit <= 9; digit++){
            if(sum >= digit)
                ans += dp[n - 1][sum - digit];
        }
        if(ans == 0) return -1;
        return ans;
    }
};

// 1-9 = maxSum = 9
// 10-99 = maxSum = 18
// 100-999 = maxSum = 27
// 1000-9999 = maxSum = 36
// 10000-99999 = maxSum = 45
// 100000-999999 = maxSum = 54
// 1000000-9999999 = maxSum = 63
// 10000000-99999999 = maxSum = 72
// 100000000-999999999 = maxSum = 81
