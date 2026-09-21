
class Solution {
  public:
    int MOD = 1e9 + 7;
    int countSubsequences(string& s, int n) {
        // dp[r] = number of non-empty subsequences
        // having remainder r when divided by n
        vector<int> dp(n, 0);
        for(char ch : s) {
            int digit = ch - '0';

            // Copy old states
            // because we can choose NOT to take current digit
            vector<int> next = dp;
            // Current digit itself forms a subsequence
            int rem = digit % n;
            next[rem]++;
            if(next[rem] >= MOD) {
                next[rem] -= MOD;
            }

            // Append current digit to every
            // previously existing subsequence
            for(int r = 0; r < n; r++) {
                if(dp[r] == 0) {
                    continue;
                }
                int newRem = (r * 10 + digit) % n;
                next[newRem] = (next[newRem] + dp[r]) % MOD;
            }
            dp = next;
        }
        return dp[0];
    }
};