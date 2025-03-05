
#include <iostream>
#include <vector>
using namespace std;

int f(int i, int j, string &s1, string &s2, vector<vector<int>> &dp) {
    if (i < 0 || j < 0) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    if (s1[i] == s2[j]) {
        return dp[i][j] = 1 + f(i - 1, j - 1, s1, s2, dp);
    }
    return dp[i][j] = max(f(i - 1, j, s1, s2, dp), f(i, j - 1, s1, s2, dp));
}

int lcs(string &s1, string &s2) {
    int m = s1.size();
    int n = s2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    return f(m - 1, n - 1, s1, s2, dp);
}

int main() {
    string s1 = "abcde", s2 = "ace";
    cout << "Length of LCS: " << lcs(s1, s2) << endl;
    return 0;
}
