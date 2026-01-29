
typedef long long ll;

ll solve(int i, int j, int isTrue, string &s, vector<vector<vector<ll>>> &dp) {
    if (i > j) return 0;
    if (i == j) {
        if (isTrue) return s[i] == 'T';
        else return s[i] == 'F';
    }
    if (dp[i][j][isTrue] != -1) return dp[i][j][isTrue];

    ll ways = 0;
    for (int idx = i + 1; idx <= j - 1; idx += 2) {
        ll leftTrue = solve(i, idx - 1, 1, s, dp);
        ll rightTrue = solve(idx + 1, j, 1, s, dp);
        ll leftFalse = solve(i, idx - 1, 0, s, dp);
        ll rightFalse = solve(idx + 1, j, 0, s, dp);

        if (s[idx] == '&') {
            if (isTrue) ways += (leftTrue * rightTrue);
            else ways += (leftTrue * rightFalse) + (leftFalse * rightTrue) + (leftFalse * rightFalse);
        } else if (s[idx] == '|') {
            if (isTrue) ways += (leftTrue * rightTrue) + (leftTrue * rightFalse) + (leftFalse * rightTrue);
            else ways += (leftFalse * rightFalse);
        } else if (s[idx] == '^') {
            if (isTrue) ways += (leftTrue * rightFalse) + (leftFalse * rightTrue);
            else ways += (leftTrue * rightTrue) + (leftFalse * rightFalse);
        }
    }
    return dp[i][j][isTrue] = ways;
}

int countWays(string &s) {
    int n = s.size();
    vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>>(n + 1, vector<ll>(2, -1)));
    return solve(0, n - 1, 1, s, dp);
}
