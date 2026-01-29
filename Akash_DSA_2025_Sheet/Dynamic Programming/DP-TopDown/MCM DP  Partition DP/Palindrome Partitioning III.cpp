
class Solution {
public:
// forward partition or front partition
// You cut forward
// You don’t go left
// Partition grows from left → right
// ✅ That is Forward DP
// 🔥 Forward Partition DP (1D DP on Index)
// also known as
// Palindrome Partitioning – DP on Prefix
// First, change some characters of s to other lowercase English letters.
// Then divide s into k non-empty disjoint substrings such that each substring is a palindrome.
// Return the minimal number of characters that you need to change to divide the string.
    int palindromePartition(string s, int k) {
        int n = s.size();
        // cost[i][j] = min changes to make s[i..j] palindrome
        vector<vector<int>> cost(n, vector<int>(n, 0));

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                cost[i][j] = cost[i + 1][j - 1];
                if (s[i] != s[j]) cost[i][j]++;
            }
        }
        // dp[i][p] = min cost to split s[i..] into p palindromes
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 1e9));
        dp[n][0] = 0;
        for (int i = n - 1; i >= 0; i--) {
            for (int p = 1; p <= k; p++) {
                for (int j = i; j < n; j++) {
                    dp[i][p] = min(dp[i][p],
                                   cost[i][j] + dp[j + 1][p - 1]);
                }
            }
        }
        return dp[0][k];
    }
};