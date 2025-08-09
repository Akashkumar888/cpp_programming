
class Solution {
public:
    int getLongestPrefix(string &s) {
        int n = s.size();
        if (n <= 1) return -1;

        for (int len = n - 1; len >= 1; len--) {
            string prefix = s.substr(0, len);
            string repeated = "";
            while ((int)repeated.size() < n) {
                repeated += prefix;
            }
            if (repeated.substr(0, n) == s) {
                return len;
            }
        }

        return -1;
    }
};
// Time Complexity
// Z-function construction:
// Runs in O(n) because each character is visited at most twice — once when expanding the Z-box, and once when shrinking.
// Longest periodic prefix check:
// Scanning from n-1 down to 1 is O(n).
// Total: O(n) + O(n) = O(n).

// Space Complexity
// Z array: Needs an array of size n → O(n) extra space.
// No other significant storage is used → O(n) total auxiliary space.
// The input string itself is O(n), but that’s given.


