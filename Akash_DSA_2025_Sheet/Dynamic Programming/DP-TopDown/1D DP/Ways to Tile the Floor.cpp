
class Solution {
  public:
    int MOD = 1e9 + 7;
    int solve(int n, int m, vector<int> &dp){
        if(n < m) return 1;
        if(n == m) return 2;
        
        if(dp[n] != -1) return dp[n];
        
        int horizontal = solve(n - 1, m, dp);

        int vertical = solve(n - m, m, dp);

        return dp[n] = (horizontal + vertical) % MOD;
    }

    int countWays(int n, int m) {
        vector<int> dp(n + 1, -1);
        return solve(n, m, dp);
    }
};



class Solution {
  public:
    int MOD = 1e9 + 7;
    int countWays(int n, int m) {
        vector<long long> dp(n + 1, 0);
        dp[0] = 1;
        for(int i = 1; i <= n; i++) {
            if(i < m) dp[i] = 1;
            else if(i == m){
                dp[i] = 2;
            }
            else{
                int horizontal = dp[i - 1];

                int vertical = dp[i - m];

                dp[i] = (horizontal + vertical) % MOD;
            }
        }
        return dp[n];
    }
};