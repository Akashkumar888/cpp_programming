
class Solution {
public:
    int countWithout(int n, int d) {
        if (n == 0)return 0;

        string s = to_string(n);
        int len = s.size();

        long long ans = 0;

        // --------------------------------------------
        // Count valid numbers having fewer digits
        // than n.
        // --------------------------------------------
        long long power9 = 1;
        for (int digits = 1; digits < len; digits++) {
            if (d == 0) {
                // First digit: 1-9 -> 9 choices
                // Remaining digits: 1-9 -> 9 choices
                ans += 9 * power9;
            }
            else {
                // First digit: 1-9 except d -> 8 choices
                // Remaining digits: 0-9 except d -> 9 choices
                ans += 8 * power9;
            }
            power9 *= 9;
        }

        // --------------------------------------------
        // Count valid numbers having the same number
        // of digits as n.
        // --------------------------------------------
        for (int i = 0; i < len; i++) {
            int current = s[i] - '0';
            int smaller = 0;
            for (int digit = 0; digit < current; digit++) {
                // Leading zero is not allowed.
                if (i == 0 && digit == 0) continue;

                // Forbidden digit is not allowed.
                if (digit == d) continue;
                smaller++;
            }

            // Number of ways to fill remaining positions.
            long long ways = 1;
            for (int j = i + 1; j < len; j++) {
                ways *= 9;
            }
            ans += smaller * ways;
            // If current digit is forbidden,
            // we cannot continue matching n.
            if (current == d) return ans;
        }
        // n itself does not contain d.
        return ans + 1;
    }
}; 