
class Solution {
public://It's guaranteed that you can reach nums[n - 1].
    int solve(int i, vector<int>& nums, vector<int>& dp) {
        int n = nums.size();

        // If already at or beyond last index → no jumps needed
        if (i >= n - 1) return 0;

        // DP memo
        if (dp[i] != -1) return dp[i];

        int minSteps = INT_MAX;

        // Try all possible jumps from index i
        for (int j = 1; j <= nums[i]; j++) {
            int next = i + j;
            if (next < n) {
                int sub = solve(next, nums, dp);
                if (sub != INT_MAX) {
                    minSteps = min(minSteps, 1 + sub);
                }
            }
        }

        return dp[i] = minSteps;
    }

    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return solve(0, nums, dp);
    }
};
