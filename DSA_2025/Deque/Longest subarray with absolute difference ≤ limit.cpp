
int longestSubarray(vector<int>& nums, int limit) {
    deque<int> minDq, maxDq;
    int left = 0, ans = 0;

    for (int right = 0; right < nums.size(); right++) {
        while (!minDq.empty() && nums[minDq.back()] >= nums[right]) minDq.pop_back();
        while (!maxDq.empty() && nums[maxDq.back()] <= nums[right]) maxDq.pop_back();

        minDq.push_back(right);
        maxDq.push_back(right);

        while (nums[maxDq.front()] - nums[minDq.front()] > limit) {
            if (minDq.front() == left) minDq.pop_front();
            if (maxDq.front() == left) maxDq.pop_front();
            left++;
        }

        ans = max(ans, right - left + 1);
    }
    return ans;
}

