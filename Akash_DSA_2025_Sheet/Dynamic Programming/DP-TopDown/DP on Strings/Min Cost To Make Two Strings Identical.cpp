
class Solution {
public:

    long long solve(int i, int j,
                    string &s1, string &s2,
                    int costS1, int costS2,
                    vector<vector<long long>> &dp) {

        // s1 is empty
        if (i == 0) {
            return 1LL * j * costS2;
        }

        // s2 is empty
        if (j == 0) {
            return 1LL * i * costS1;
        }

        // Already calculated
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        // Characters are same
        if (s1[i - 1] == s2[j - 1]) {

            return dp[i][j] =
                solve(i - 1, j - 1,
                      s1, s2,
                      costS1, costS2,
                      dp);
        }

        // Characters are different
        long long deleteFromS1 =
            costS1 + solve(i - 1, j,
                           s1, s2,
                           costS1, costS2,
                           dp);

        long long deleteFromS2 =
            costS2 + solve(i, j - 1,
                           s1, s2,
                           costS1, costS2,
                           dp);

        return dp[i][j] = min(deleteFromS1, deleteFromS2);
    }

    int findMinCost(string &s1, string &s2,
                    int costS1, int costS2) {

        int n = s1.size();
        int m = s2.size();

        vector<vector<long long>> dp(
            n + 1,
            vector<long long>(m + 1, -1)
        );

        return solve(n, m, s1, s2,
                     costS1, costS2, dp);
    }
};



class Solution {
public:
    int findMinCost(string &s1, string &s2, int costS1, int costS2) {

        int n = s1.size();
        int m = s2.size();

        vector<vector<long long>> dp(n + 1,
                                     vector<long long>(m + 1, 0));

        // s2 is empty
        // Delete all characters from s1
        for (int i = 1; i <= n; i++) {
            dp[i][0] = 1LL * i * costS1;
        }

        // s1 is empty
        // Delete all characters from s2
        for (int j = 1; j <= m; j++) {
            dp[0][j] = 1LL * j * costS2;
        }

        for (int i = 1; i <= n; i++) {

            for (int j = 1; j <= m; j++) {

                if (s1[i - 1] == s2[j - 1]) {

                    // Keep both characters
                    dp[i][j] = dp[i - 1][j - 1];

                } else {

                    // Delete from s1 OR delete from s2
                    dp[i][j] = min(
                        costS1 + dp[i - 1][j],
                        costS2 + dp[i][j - 1]
                    );
                }
            }
        }

        return dp[n][m];
    }
};

