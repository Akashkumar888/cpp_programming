
class Solution {
  public:
    int maxIndexDifference(string &s) {

        int n = s.size();

        vector<int> dp(n);

        // best[ch] = maximum reachable index from any processed occurrence
        vector<int> best(26, -1);

        // Process from right to left
        for(int i = n - 1; i >= 0; i--) {

            int ch = s[i] - 'a';

            dp[i] = i;

            // Can jump to next alphabet
            if(ch < 25 && best[ch + 1] != -1) {
                dp[i] = max(dp[i], best[ch + 1]);
            }

            // Update best for this character
            best[ch] = max(best[ch], dp[i]);
        }

        int ans = -1;

        for(int i = 0; i < n; i++) {

            if(s[i] == 'a') {
                ans = max(ans, dp[i] - i);
            }
        }

        return ans;
    }
};