
// The greedy works because the "failure at station i" implies all stations before i cannot be the answer, so you only move forward.

class Solution {
  public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        int n = gas.size();

        // Step 1: Check overall feasibility
        // If the total gas is less than the total cost, it is impossible
        int gasSum = accumulate(gas.begin(), gas.end(), 0);
        int costSum = accumulate(cost.begin(), cost.end(), 0);
        if (gasSum < costSum) return -1;

        // Step 2: Greedy check to find valid starting station
        int idx = 0;     // candidate starting index
        int total = 0;   // current fuel balance

        for (int i = 0; i < n; i++) {
            total += (gas[i] - cost[i]); // add net gain/loss at station i

            // If balance goes negative, we cannot reach i+1 from current idx
            if (total < 0) {
                idx = i + 1;  // next station becomes new candidate
                total = 0;    // reset balance for the new start
            }
        }

        // At the end, idx is guaranteed to be the valid starting point
        return idx;
    }
};



// ⏱️ Time Complexity
// Accumulating sums → O(n)
// Iterating through stations once → O(n)
// Total: O(n)

// 💾 Space Complexity
// Only a few variables (idx, total, gasSum, costSum).
// No extra data structures used.
// Space: O(1)
