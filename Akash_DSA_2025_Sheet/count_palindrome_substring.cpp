
#include <bits/stdc++.h>
using namespace std;

bool palindrome(int i, int j, string &s, vector<vector<int>> &dp) {
    if (i >= j) return true;
    if (dp[i][j] != -1) return dp[i][j];
    if (s[i] == s[j]) return dp[i][j] = palindrome(i + 1, j - 1, s, dp);
    return dp[i][j] = false;
}

int countPS(string &s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    int count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) { // Ensure length >= 2
            if (palindrome(i, j, s, dp)) count++;
        }
    }
    return count;
}

int main() {
    string s = "abba";
    cout << "Count of Palindromic Subsequences: " << countPS(s) << endl;
    return 0;
}

