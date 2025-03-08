
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

bool palindrome(int i, int j, string &s, vector<vector<int>>&dp) {
    if (i >= j) return true;
    if (dp[i][j] != -1) return dp[i][j];
    if (s[i] == s[j]) return dp[i][j] = palindrome(i + 1, j - 1, s, dp);
    return dp[i][j] = false;
}

string longestPalindrome(string &s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    int start = 0, maxlen = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (palindrome(i, j, s, dp)) {
                if (j - i + 1 > maxlen) {
                    maxlen = j - i + 1;
                    start = i;
                }
            }
        }
    }
    return s.substr(start, maxlen);
}

int main() {
    string s;
    cin >> s;
    cout << longestPalindrome(s) << endl;
    return 0;
}
