
long long sumOfMinMax(vector<int>& nums, int k) {
    deque<int> minDq, maxDq;
    long long sum = 0;

    for (int i = 0; i < nums.size(); i++) {
        if (!minDq.empty() && minDq.front() <= i - k) minDq.pop_front();
        if (!maxDq.empty() && maxDq.front() <= i - k) maxDq.pop_front();

        while (!minDq.empty() && nums[minDq.back()] >= nums[i]) minDq.pop_back();
        while (!maxDq.empty() && nums[maxDq.back()] <= nums[i]) maxDq.pop_back();

        minDq.push_back(i);
        maxDq.push_back(i);

        if (i >= k - 1) sum += nums[minDq.front()] + nums[maxDq.front()];
    }
    return sum;
}

