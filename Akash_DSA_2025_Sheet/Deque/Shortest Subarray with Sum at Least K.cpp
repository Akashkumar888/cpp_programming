
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;
        vector<long long> prefix(n + 1, 0);

        // Compute prefix sum
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        int minlen = INT_MAX;

        for (int i = 0; i <= n; i++) {
            // Ensure the window is valid (sum ≥ k)
            while (!dq.empty() && prefix[i] - prefix[dq.front()] >= k) {
                minlen = min(minlen, i - dq.front());
                dq.pop_front();
            }

            // Maintain a monotonic increasing deque
            while (!dq.empty() && prefix[i] <= prefix[dq.back()]) {
                dq.pop_back();
            }

            dq.push_back(i);
        }

        return (minlen == INT_MAX) ? -1 : minlen;
    }
};
