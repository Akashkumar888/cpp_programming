
class Solution {
public:
    vector<int> minOfSubarrays(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> result;
        deque<int> dq; // store indices

        for (int i = 0; i < n; i++) {

            // Step 1: Remove out-of-window elements
            if (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            // Step 2: Maintain increasing order (for MIN)
            while (!dq.empty() && arr[dq.back()] > arr[i]) {
                dq.pop_back();
            }

            dq.push_back(i);

            // Step 3: Store answer when window is ready
            if (i - k + 1 >= 0) {
                result.push_back(arr[dq.front()]);
            }
        }
        return result;
    }
};
