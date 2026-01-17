
// This follows exactly your Two Pointer / Sliding Window idea:
// Move i over s1 and match characters of s2 using j.
// When j == m, a valid subsequence window ends at i.
// Shrink from left by moving backward and matching s2 in reverse.
// Update the minimum window.
// Continue searching.
// Time Complexity: O(N * M)
// Space Complexity: O(1)

class Solution {
  public:
    string minWindow(string& s1, string& s2) {
        int n = s1.size(), m = s2.size();
        int i = 0, j = 0;
        int minLen = INT_MAX;
        int start = -1;

        while (i < n) {
            // Forward match s2 in s1
            if (s1[i] == s2[j]) {
                j++;
            }

            // When full s2 matched
            if (j == m) {
                int end = i;
                j--;          // move back in s2
                int k = i;

                // Backward shrinking
                while (k >= 0) {
                    if (s1[k] == s2[j]) {
                        j--;
                        if (j < 0) break;
                    }
                    k--;
                }

                int len = end - k + 1;
                if (len < minLen) {
                    minLen = len;
                    start = k;
                }

                // Reset for next search
                i = k + 1;
                j = 0;
            }

            i++;
        }

        if (start == -1) return "";
        return s1.substr(start, minLen);
    }
};
// How it works:
// Move i over s1.
// Use j to match characters of s2 in order.
// When j == m, it means s2 is fully matched as a subsequence ending at i.
// Now we shrink from left:
// Move backward from i to find the earliest start that still keeps s2 as a subsequence.
// This gives the minimum window ending at i.
// Compare with previous best and update.
// Reset pointers and continue.
// This simulates DP behavior but uses only pointers → space O(1).


// 1️⃣ Two-Pointer + Backtracking (O(N·M), O(1))
class Solution {
public:
    string minWindow(string &s1, string &s2) {
    int n = s1.size();
    int m = s2.size();
    string ans = "";
    int minLen = INT_MAX;

    for (int i = 0; i < n; i++) {
        // Start only when first character matches
        if (s1[i] == s2[0]) {
            int p1 = i, p2 = 0;

            // Forward match s2 in s1
            while (p1 < n && p2 < m) {
                if (s1[p1] == s2[p2]) p2++;
                p1++;
            }

            // If full s2 matched
            if (p2 == m) {
                int end = p1 - 1;
                p2 = m - 1;

                // Backtrack to minimize window
                while (end >= i) {
                    if (s1[end] == s2[p2]) p2--;
                    if (p2 < 0) break;
                    end--;
                }

                int start = end;
                int len = p1 - start;
                if (len < minLen) {
                    minLen = len;
                    ans = s1.substr(start, len);
                }
            }
        }
    }
    return ans;
}
};


// 2️⃣ Preprocessed Next-Occurrence Table (O(N·M), O(N·26))
class Solution {
public:
string minWindow(string &s1, string &s2) {
    int n = s1.size();
    int m = s2.size();

    // nextPos[i][c] = next index of character c after position i in s1
    vector<vector<int>> nextPos(n + 1, vector<int>(26, -1));

    // Build nextPos table
    for (int c = 0; c < 26; c++) nextPos[n][c] = -1;

    for (int i = n - 1; i >= 0; i--) {
        nextPos[i] = nextPos[i + 1];
        nextPos[i][s1[i] - 'a'] = i;
    }

    string ans = "";
    int minLen = INT_MAX;

    // Try each possible start
    for (int start = 0; start < n; start++) {
        if (s1[start] != s2[0]) continue;

        int idx = start;
        bool ok = true;

        for (int j = 0; j < m; j++) {
            if (idx == -1) { ok = false; break; }
            idx = nextPos[idx][s2[j] - 'a'];
            if (idx == -1) { ok = false; break; }
            idx++; // move for next character
        }

        if (ok) {
            int endIdx = idx - 1;
            int len = endIdx - start + 1;
            if (len < minLen) {
                minLen = len;
                ans = s1.substr(start, len);
            }
        }
    }

    return ans;
}
};



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
// dp[i][j] = starting index in s1 of a window ending at i
//            such that s2[0..j] is a subsequence of s1[0..i]
//            Meaning:
// If characters match:
// For first char of s2, window starts at i.
// Otherwise, inherit the start index from dp[i-1][j-1].
// If they don’t match:
// Carry forward the previous result from dp[i-1][j].
// After DP is built:
// for each i:
//     if dp[i][m-1] != -1:
//         window length = i - dp[i][m-1] + 1
//         take minimum
//         So:
// The last column dp[i][m-1] tells:
// “Is there a subsequence s2 ending at i? If yes, where does it start?”
// We just choose the smallest such window.
