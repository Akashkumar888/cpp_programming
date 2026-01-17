
class Solution {
public:
    bool isPalindrome(int i, int j, string &s) {
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++; j--;
        }
        return true;
    }

    bool checkPartitioning(string s) {
        int n = s.size();

        // First cut
        for (int i = 0; i < n - 2; i++) {
            if (!isPalindrome(0, i, s)) continue;

            // Second cut
            for (int j = i + 1; j < n - 1; j++) {
                if (isPalindrome(i + 1, j, s) &&
                    isPalindrome(j + 1, n - 1, s)) {
                    return true;
                }
            }
        }
        return false;
    }
};