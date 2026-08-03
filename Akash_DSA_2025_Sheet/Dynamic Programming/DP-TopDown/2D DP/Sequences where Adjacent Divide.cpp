
class Solution {
public:
    int solve(int &len, int &last, int &n, int &m,vector<vector<int>> &dp) {
        if (len == n) return 1;
        if (dp[len][last] != -1) return dp[len][last];
        int ans = 0;
        for (int nxt = 1; nxt <= m; nxt++) {
            if (last % nxt == 0 || nxt % last == 0) {
                int newLen = len + 1;
                int newLast = nxt;
                ans += solve(newLen, newLast, n, m, dp);
            }
        }
        return dp[len][last] = ans;
    }
    int count(int n, int m) {
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        int ans = 0;
        for (int first = 1; first <= m; first++) {
            int len = 1;
            int last = first;
            ans += solve(len, last, n, m, dp);
        }
        return ans;
    }
};


class Solution {
public:
    int count(int n, int m) {

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Base case
        for (int last = 1; last <= m; last++) {
            dp[n][last] = 1;
        }

        // Fill table
        for (int len = n - 1; len >= 1; len--) {

            for (int last = 1; last <= m; last++) {

                int ans = 0;

                for (int nxt = 1; nxt <= m; nxt++) {

                    if (last % nxt == 0 || nxt % last == 0) {
                        ans += dp[len + 1][nxt];
                    }
                }

                dp[len][last] = ans;
            }
        }

        int ans = 0;

        for (int first = 1; first <= m; first++) {
            ans += dp[1][first];
        }

        return ans;
    }
};