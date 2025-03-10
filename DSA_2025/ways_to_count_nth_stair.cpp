
#include <bits/stdc++.h>
using namespace std;

int solve(int n, vector<int>& dp) {
    if (n == 1) return 1;
    if (n == 2) return 2;
    
    if (dp[n] != -1) return dp[n];
    
    return dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
}

int countWays(int n) {
    vector<int> dp(n + 1, -1);
    return solve(n, dp);
}

int main() {
    int n = 10; // Example input
    cout << "Ways to reach step " << n << ": " << countWays(n) << endl;
    return 0;
}
