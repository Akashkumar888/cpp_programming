
vector<int> firstNegativeInWindow(vector<int>& nums, int k) {
    deque<int> dq; // store indices of negative numbers
    vector<int> ans;

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] < 0) dq.push_back(i);

        if (i >= k - 1) {
            while (!dq.empty() && dq.front() <= i - k) dq.pop_front();
            ans.push_back(dq.empty() ? 0 : nums[dq.front()]);
        }
    }
    return ans;
}


