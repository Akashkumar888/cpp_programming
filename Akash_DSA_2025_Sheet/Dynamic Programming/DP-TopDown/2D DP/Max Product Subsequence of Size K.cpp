
class Solution {
public:
    int maxProduct(vector<int>& arr, int k) {

        int n = arr.size();

        const long long INF = 4e18;

        // dp[j][0] = maximum product using exactly j elements
        // dp[j][1] = minimum product using exactly j elements
        vector<vector<long long>> dp(k + 1,
                                    vector<long long>(2));

        for (int j = 0; j <= k; j++) {
            dp[j][0] = -INF;
            dp[j][1] = INF;
        }

        // Product of selecting 0 elements = 1
        dp[0][0] = 1;
        dp[0][1] = 1;

        for (int x : arr) {

            for (int j = k; j >= 1; j--) {

                // We need j-1 selected elements before taking x
                if (dp[j - 1][0] != -INF) {

                    long long p = dp[j - 1][0] * x;

                    dp[j][0] = max(dp[j][0], p);
                    dp[j][1] = min(dp[j][1], p);
                }

                if (dp[j - 1][1] != INF) {

                    long long p = dp[j - 1][1] * x;

                    dp[j][0] = max(dp[j][0], p);
                    dp[j][1] = min(dp[j][1], p);
                }
            }
        }

        return (int)dp[k][0];
    }
};