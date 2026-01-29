
// A stack is one-ended (LIFO), so we can only maintain monotonicity when looking backward (like Next Greater/Smaller problems).
// A queue is FIFO, so you can’t efficiently maintain monotonic order while pushing/popping from just one side.
// That’s why we use a deque (double-ended queue) ➝ it lets us:
// Pop from front → to remove indices that go out of the sliding window (older than allowed).
// Pop from back → to maintain monotonic order of prefix sums.
// Push at back → add the new candidate prefix.
// So the structure is often called a monotonic queue, but the implementation is always via a deque.

class Solution {
  public:
    int maxSubarrSum(vector<int>& arr, int a, int b) {
        // code here
        int n = arr.size();
        vector<int> prefix(n+1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i+1] = prefix[i] + arr[i];
        }
        int maxSum = INT_MIN;
        deque<int> dq;  // stores indices of prefix sums
        for (int j = 0; j <= n; j++) {
            // Remove indices out of left bound (older than j-b)
            while (!dq.empty() && dq.front() < j - b) dq.pop_front();
            
            // Insert new candidate prefix[j-a] (if valid)
            if (j >= a) {
                int idx = j - a;
                // Maintain increasing order of prefix values
                while (!dq.empty() && prefix[dq.back()] >= prefix[idx]) {
                    dq.pop_back();
                }
                dq.push_back(idx);
            }
            
            // If deque not empty, update maxSum
            if (!dq.empty()) {
                maxSum = max(maxSum, (prefix[j] - prefix[dq.front()]));
            }
        }
        return maxSum;
    }
};
