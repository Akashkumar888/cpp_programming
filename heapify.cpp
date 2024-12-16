
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    typedef pair<int, int> P;

    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();
        vector<P> pq;

        // Build the initial heap
        for (int i = 0; i < n; i++) {
            pq.push_back({nums[i], i});
        }
        make_heap(pq.begin(), pq.end(), greater<>());

        // Perform k updates
        while (k-- && !pq.empty()) {
            // Pop the smallest element
            pop_heap(pq.begin(), pq.end(), greater<>());
            P smallest = pq.back();
            pq.pop_back();

            // Update the value and push it back into the heap
            int newVal = smallest.first * multiplier;
            int idx = smallest.second;
            pq.push_back({newVal, idx});
            push_heap(pq.begin(), pq.end(), greater<>());
        }

        // Update the nums array with the final heap state
        for (const auto& p : pq) {
            nums[p.second] = p.first;
        }

        return nums;
    }
};
