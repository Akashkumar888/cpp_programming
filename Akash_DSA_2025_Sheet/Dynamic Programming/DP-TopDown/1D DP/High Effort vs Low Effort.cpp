
class Solution {
public:
    int solve(int i, vector<int>& h, vector<int>& l,vector<int>& dp) {
        // No days left
        if(i < 0)return 0;

        // Already calculated
        if(dp[i] != -1)return dp[i];

        // Option 1: Do nothing today
        int noTask = solve(i - 1, h, l, dp);

        // Option 2: Perform low-effort task today
        int low = l[i] + solve(i - 1, h, l, dp);

        // Option 3: Perform high-effort task today
        // Previous day must be skipped
        int high = h[i] + solve(i - 2, h, l, dp);

        // Take maximum
        return dp[i] = max(noTask, max(low, high));
    }
    int maxTask(vector<int>& h, vector<int>& l) {
        int n = h.size();
        vector<int> dp(n, -1);
        return solve(n - 1, h, l, dp);
    }
};



class Solution {
public:
    int maxTask(vector<int>& h, vector<int>& l) {
        int n = h.size();
        vector<int> dp(n + 1, 0);
        // No days
        dp[0] = 0;
        // First day
        dp[1] = max(h[0], l[0]);
        for(int i = 2; i <= n; i++) {
            // Day index = i - 1
            // Do nothing
            int noTask = dp[i - 1];
            // Low-effort task
            int low = dp[i - 1] + l[i - 1];
            // High-effort task
            // Previous day must be skipped
            int high = dp[i - 2] + h[i - 1];
            dp[i] = max(noTask, max(low, high));
        }
        return dp[n];
    }
};


class Solution {
public:
    int maxTask(vector<int>& h, vector<int>& l) {
        int n = h.size();
        // dp[i-2]
        int prev2 = 0;
        // dp[i-1]
        int prev1 = 0;
        for(int i = 0; i < n; i++) {
            // Do nothing today
            int noTask = prev1;
            // Low-effort task
            int low = prev1 + l[i];
            // High-effort task
            // Previous day must be skipped
            int high = prev2 + h[i];
            // Best answer till today
            int curr = max(noTask, max(low, high));
            // Move DP states
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};