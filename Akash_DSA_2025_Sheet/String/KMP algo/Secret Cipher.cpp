
// 1️⃣ Secret Cipher
// 🔹 Idea
// We need to find the lexicographically smallest encrypted string.
// The '*' operation means:
// If we have:
//     X X
// then the second X can be replaced by '*':
//     X*
// because '*' takes all characters before it and appends them again.
// Example:
//     ababcababc
// Here:
//     ababc + ababc
// So:
//     ababcababc
//          ↓
//     ababc*d
// For this problem, we need to find such repeated prefixes efficiently.
// We use KMP's LPS array.
// 🔹 What is LPS?
// LPS[i] = length of the longest proper prefix of
//          s[0...i] which is also a suffix.
// Example:
//     s = "abab"
//     LPS = [0, 0, 1, 2]
// 🔹 Important Observation
// Suppose the current prefix has length len.
// If the prefix is:
//     X + X
// then its second half is the same as its first half.
// We can detect this repetition using LPS.
// period = len - lps[len-1]
// If the string is periodic, then:
//     len % period == 0
// For this problem, we also need the repeated part
// to be at least half of the current string.
// 🔹 Why do we process from RIGHT to LEFT?
// We want to find the largest prefix that can be compressed.
// For example:
//     ababcababcd
// First:
//     ababcababcd
//          ↓
//     ababc*d
// Then:
//     ababc
//       ↓
//     ab*c
// Therefore:
//     ab*c*d
// Processing from right to left allows us to find these
// compressible repeated prefixes.
//
// 🔹 Time Complexity
// LPS construction → O(n)
// Traversing string → O(n)
// Total Time: O(n)
// Space: O(n)
//
// ------------------------------------------------------------
class Solution {
public:
    // 1️⃣ KMP - Build LPS Array
    //
    // lps[i] = length of the longest proper prefix
    //          which is also a suffix ending at i.

    void KMP(string &s, vector<int> &lps) {
        int pre = 0;
        int suf = 1;
        while (suf < s.size()) {
            // Characters match
            if (s[pre] == s[suf]) {
                lps[suf] = pre + 1;
                pre++;
                suf++;
            }
            // Characters do not match
            else {
                // No prefix is possible
                if (pre == 0) {
                    lps[suf] = 0;
                    suf++;
                }
                // Try the previous longest prefix
                else {
                    pre = lps[pre - 1];
                }
            }
        }
    }
    string compress(string &s) {
        int n = s.size();
        // -------------------------------------------------
        // Step 1️⃣
        // Build LPS array
        // -------------------------------------------------
        vector<int> lps(n, 0);
        KMP(s, lps);
        // -------------------------------------------------
        // Step 2️⃣
        // Build answer from RIGHT to LEFT
        // -------------------------------------------------
        string ans;
        int i = n - 1;
        while (i >= 0) {
            // -------------------------------------------------
            // A repeated string must have even length
            //
            // Example:
            //
            //     "abab"
            //
            // len = 4
            //
            //     "ab" + "ab"
            //
            // -------------------------------------------------
            if (i % 2 == 1) {
                int len = i + 1;
                // -------------------------------------------------
                // Find the smallest repeating period
                //
                // period = len - lps[i]
                //
                // Example:
                //
                // "abab"
                //
                // len = 4
                // lps[3] = 2
                //
                // period = 4 - 2 = 2
                //
                // "ab" + "ab"
                // -------------------------------------------------
                int period = len - lps[i];
                // -------------------------------------------------
                // Check whether the current prefix can be
                // represented as repeated parts.
                //
                // lps[i] >= len/2
                //
                // means at least half of the string is repeated.
                //
                // len % (2 * period) == 0
                //
                // ensures that the required repeated structure
                // fits completely.
                // -------------------------------------------------
                if (lps[i] >= len / 2 &&
                    len % (2 * period) == 0) {

                    // Replace the repeated second part by '*'
                    ans += '*';
                    // Move to the first half
                    //
                    // Example:
                    //
                    //     "ababcababc"
                    //
                    //              i
                    //
                    // After '*', we only need to process
                    // the first half.
                    //
                    i = i / 2 + 1;
                }
                else {
                    // Current character cannot be compressed
                    ans += s[i];
                }
            }
            else {
                // Odd length prefix cannot be divided into
                // two equal halves
                ans += s[i];
            }
            i--;
        }
        // We created answer from right to left
        // so reverse it.
        reverse(ans.begin(), ans.end());
        return ans;
    }
};