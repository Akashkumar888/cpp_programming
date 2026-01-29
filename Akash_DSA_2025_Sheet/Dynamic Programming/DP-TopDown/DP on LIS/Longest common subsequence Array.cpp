
// 1️⃣ PURE RECURSION + MEMO (0-based indexing)
class Solution {
public:
    int solve(int i, int j, vector<int>& a, vector<int>& b, vector<vector<int>>& dp) {
        if (i < 0 || j < 0) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        if (a[i] == b[j])
            return dp[i][j] = 1 + solve(i - 1, j - 1, a, b, dp);

        return dp[i][j] = max(solve(i - 1, j, a, b, dp),
                             solve(i, j - 1, a, b, dp));
    }

    int LCS(vector<int>& a, vector<int>& b) {
        int n = a.size(), m = b.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(n - 1, m - 1, a, b, dp);
    }
};


// ✅ 2️⃣ RECURSION + MEMO (1-based indexing)
class Solution {
public:
    int solve(int i, int j, vector<int>& a, vector<int>& b, vector<vector<int>>& dp) {
        if (i == 0 || j == 0) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        if (a[i - 1] == b[j - 1])
            return dp[i][j] = 1 + solve(i - 1, j - 1, a, b, dp);

        return dp[i][j] = max(solve(i - 1, j, a, b, dp),
                             solve(i, j - 1, a, b, dp));
    }

    int LCS(vector<int>& a, vector<int>& b) {
        int n = a.size(), m = b.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return solve(n, m, a, b, dp);
    }
};

// ✅ 3️⃣ PURE BOTTOM-UP TABULATION (ITERATIVE DP)
class Solution {
public:
    int LCS(vector<int>& a, vector<int>& b) {
        int n = a.size();
        int m = b.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {

                if (a[i - 1] == b[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];

                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[n][m];
    }
};


// CSES Problem Set
// Longest Common Subsequence
// https://cses.fi/problemset/task/3403/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);
    for(int &x : a) cin >> x;
    for(int &x : b) cin >> x;

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    // Fill DP Table
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1]==b[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    cout << dp[n][m] << "\n";   // PRINT LENGTH

    // 🔁 Reconstruct LCS
    vector<int> ans;
    int i=n, j=m;
    while(i>0 && j>0){
        if(a[i-1] == b[j-1]){
            ans.push_back(a[i-1]);
            i--, j--;
        }
        else if(dp[i-1][j] > dp[i][j-1])
            i--;
        else 
            j--;
    }
    reverse(ans.begin(), ans.end());

    for(int x : ans) cout << x << " ";
}


// ios::sync_with_stdio(false);
//     cin.tie(nullptr);
    // This line is VERY important in competitive programming:
//     ✅ WHY DO WE USE THIS?
// 🔹 1️⃣ ios::sync_with_stdio(false);
// 👉 Disconnects C++ I/O (cin/cout) from C I/O (scanf/printf)
// By default, cin and cout are synchronized with scanf and printf, so that:
// printf(...) + cout << ...   // work in correct order
// But synchronization slows down cin/cout.
// ⏩ Turning it OFF makes cin/cout MUCH faster.

// 🔹 2️⃣ cin.tie(nullptr);
// By default, cout is flushed automatically before every cin.
// That means:
// cout << "Enter: ";
// cin >> x;
// cout flush happens EVERY TIME, slowing code.
// cin.tie(nullptr); removes this unnecessary flush connection.
// ⏩ Makes input faster.