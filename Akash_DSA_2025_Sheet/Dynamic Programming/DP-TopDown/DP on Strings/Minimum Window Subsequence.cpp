
class Solution {
public:
    string minWindow(string& s1, string& s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (s1[i] == s2[j]) {
                    if (j == 0)dp[i][j] = i;
                    else if (i > 0)dp[i][j] = dp[i-1][j-1];
                } 
                else {
                    if (i > 0)
                        dp[i][j] = dp[i-1][j];
                }
            }
        }

        int start = -1, minLen = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (dp[i][m-1] != -1) {
                int len = i - dp[i][m-1] + 1;
                if (len < minLen) {
                    minLen = len;
                    start = dp[i][m-1];
                }
            }
        }

        if (start == -1) return "";
        return s1.substr(start, minLen);
    }
};
