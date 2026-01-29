
#include <bits/stdc++.h>
using namespace std;

int solve(int i, int j, string &s1, string &s2, vector<vector<int>> &dp) {
    if (i < 0) return j + 1; // If s1 is exhausted, insert remaining chars from s2
    if (j < 0) return i + 1; // If s2 is exhausted, remove remaining chars from s1

    if (dp[i][j] != -1) return dp[i][j];

    int mini = INT_MAX;
    if (s1[i] == s2[j])  
        mini = solve(i - 1, j - 1, s1, s2, dp);
    else {
        mini = min(mini, 1 + solve(i, j - 1, s1, s2, dp));   // Insert
        mini = min(mini, 1 + solve(i - 1, j, s1, s2, dp));   // Remove
        mini = min(mini, 1 + solve(i - 1, j - 1, s1, s2, dp)); // Replace
    }
    return dp[i][j] = mini;
}

int editDistance(string &s1, string &s2) {
    int m = s1.size();
    int n = s2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    return solve(m - 1, n - 1, s1, s2, dp);
}

int main() {
    string s1 = "horse", s2 = "ros";
    cout << "Edit Distance: " << editDistance(s1, s2) << endl;
    return 0;
}
