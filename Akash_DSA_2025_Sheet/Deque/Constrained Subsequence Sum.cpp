
int constrainedSubsetSum(vector<int>& nums, int k) {
    deque<int> dq; // store best dp candidates
    vector<int> dp(nums.size());
    int ans = INT_MIN;

    for (int i = 0; i < nums.size(); i++) {
        if (!dq.empty() && dq.front() < i - k) dq.pop_front();

        dp[i] = nums[i];
        if (!dq.empty()) dp[i] = max(dp[i], nums[i] + dp[dq.front()]);

        while (!dq.empty() && dp[dq.back()] <= dp[i]) dq.pop_back();
        dq.push_back(i);

        ans = max(ans, dp[i]);
    }
    return ans;
}
