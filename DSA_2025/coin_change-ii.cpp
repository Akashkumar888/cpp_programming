
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int i, int n, vector<int>& coins, int sum, vector<vector<int>>& dp) {
        if (sum == 0) return 1; // Found a valid way
        if (i >= n || sum < 0) return 0; // Invalid case
        
        if (dp[i][sum] != -1) return dp[i][sum]; // Memoized case
        
        int pick = 0;
        if (coins[i] <= sum) pick = solve(i, n, coins, sum - coins[i], dp);
        int notPick = solve(i + 1, n, coins, sum, dp);
        
        return dp[i][sum] = pick + notPick;
    }

    int count(vector<int>& coins, int sum) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
        return solve(0, n, coins, sum, dp);
    }
};
