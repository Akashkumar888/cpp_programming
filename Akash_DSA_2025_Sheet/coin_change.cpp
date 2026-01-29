#include <bits/stdc++.h>
using namespace std;

int solve(int i, int n, vector<int>& coins, int sum, vector<vector<int>>& dp) {
    if (i == n - 1) {
        if (sum % coins[i] == 0) return sum / coins[i];
        return 1e9;
    }
    if (dp[i][sum] != -1) return dp[i][sum];

    int pick = INT_MAX;
    if (coins[i] <= sum) pick = 1 + solve(i, n, coins, sum - coins[i], dp);
    int notpick = solve(i + 1, n, coins, sum, dp);

    return dp[i][sum] = min(pick, notpick);
}

int minCoins(vector<int>& coins, int sum) {
    int n = coins.size();
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
    int value = solve(0, n, coins, sum, dp);
    return (value == 1e9) ? -1 : value;
}

