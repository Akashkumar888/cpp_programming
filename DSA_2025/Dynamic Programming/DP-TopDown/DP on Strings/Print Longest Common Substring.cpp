
class Solution {
public:
    string longestCommonSubstring(string &s1, string &s2) {
        int n = s1.size();
        int m = s2.size();

        // dp[i][j] = length of longest common substring
        // ending at s1[i-1] and s2[j-1]
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        int maxLen = 0;     // length of longest substring
        int endIndex = -1; // ending index in s1

        // Bottom-up DP
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {

                // If characters match, extend substring
                if(s1[i-1] == s2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];

                    // Update maximum length and end index
                    if(dp[i][j] > maxLen) {
                        maxLen = dp[i][j];
                        endIndex = i - 1;  // substring ends here in s1
                    }
                }
                else {
                    // IMPORTANT: reset to 0 for substring
                    dp[i][j] = 0;
                }
            }
        }

        // If no common substring found
        if(maxLen == 0) return "";

        // Extract substring from s1
        return s1.substr(endIndex - maxLen + 1, maxLen);
    }
};


class Solution {
public:
    string longestPalindrome(string s1) {
        int n = s1.size();
        string s2=s1;
        int m = s2.size();
        reverse(s2.begin(),s2.end());
        // dp[i][j] = length of longest common substring
        // ending at s1[i-1] and s2[j-1]
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        int maxLen = 0;     // length of longest substring
        int endIndex = -1; // ending index in s1

        // Bottom-up DP
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {

                // If characters match, extend substring
                if(s1[i-1] == s2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];

                    // Update maximum length and end index
                    if(dp[i][j] > maxLen) {
                        maxLen = dp[i][j];
                        endIndex = i - 1;  // substring ends here in s1
                    }
                }
                else {
                    // IMPORTANT: reset to 0 for substring
                    dp[i][j] = 0;
                }
            }
        }

        // If no common substring found
        if(maxLen == 0) return "";

        // Extract substring from s1
        return s1.substr(endIndex - maxLen + 1, maxLen);
    }
};