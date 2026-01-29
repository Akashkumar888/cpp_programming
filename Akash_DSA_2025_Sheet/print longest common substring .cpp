
class Solution {
public:
    string longestCommonSubstr(string s, string t) {
        int m = s.size();
        int n = t.size();
        int maxLen = 0;
        int endIndex = 0;  // index where substring ends in s

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));  

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    if (dp[i][j] > maxLen) {
                        maxLen = dp[i][j];
                        endIndex = i;  // store where the substring ends in `s`
                    }
                } else {
                    dp[i][j] = 0;  // break continuity
                }
            }
        }

        // Extract substring from s using endIndex
        if (maxLen == 0) return "";  // no common substring
        return s.substr(endIndex - maxLen, maxLen);
    }
};


