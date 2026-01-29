
class Solution {
public:
    int MOD = 1e9 + 7;

    // Top-down recurrence: dp[i] = number of distinct subsequences using first i chars
    long long solve(int i, vector<long long> &dp, vector<int> &prevOcc) {
        if (i == 0) return 1;                 // empty subsequence
        if (dp[i] != -1) return dp[i];        // memo check

        long long ways = (2LL * solve(i - 1, dp, prevOcc)) % MOD;

        int prevIndex = prevOcc[i];
        if (prevIndex != -1) {
            ways = (ways - solve(prevIndex - 1, dp, prevOcc) + MOD) % MOD;
        }

        return dp[i] = ways;
    }

    int distinctSubseq(string &s) {
        int n = s.size();

        vector<long long> dp(n + 1, -1);
        vector<int> prevOcc(n + 1, -1);
        unordered_map<char, int> last;

        // Precompute prevOcc exactly like bottom-up
        for (int i = 1; i <= n; i++) {
            char ch = s[i - 1];
            if (last.count(ch))
                prevOcc[i] = last[ch];
            else
                prevOcc[i] = -1;

            last[ch] = i; // update last occurrence
        }

        long long ans = solve(n, dp, prevOcc);
        return ans % MOD;        // GFG includes empty subsequence
    }
};



class Solution {
public:
    int MOD = 1e9 + 7;

    int distinctSubseq(string &s) {
        int n = s.size();

        // dp[i] = number of distinct subsequences using first i characters
        vector<long long> dp(n + 1, 0);
        unordered_map<char, int> last;   // last index (1-based) of each character

        dp[0] = 1;   // empty subsequence

        for (int i = 1; i <= n; i++) {
            dp[i] = (2LL * dp[i - 1]) % MOD;

            char curr = s[i - 1];

            // if current character has appeared before
            if (last.count(curr)) {
                int prevIndex = last[curr];       // 1-based index
                dp[i] = (dp[i] - dp[prevIndex - 1] + MOD) % MOD;
            }

            // update last occurrence of current character
            last[curr] = i;
        }

        // GFG includes empty subsequence, so return dp[n] directly
        return (int)(dp[n] % MOD);
    }
};
