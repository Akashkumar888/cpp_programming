
class Solution {
public:
    vector<vector<int>> insertInterval(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> result;
        int i=0;
        // 1. Add all intervals before newInterval
        while (i < n && intervals[i][1] < newInterval[0]) {
            result.push_back(intervals[i]);
            i++;
        }

        // 2. Merge all overlapping intervals with newInterval
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        result.push_back(newInterval);

        // 3. Add all intervals after newInterval
        while (i < n) {
            result.push_back(intervals[i]);
            i++;
        }

        return result;
    }
};
 

// Time Complexity
// Step 1: Scan intervals before newInterval → O(k)
// Step 2: Merge overlapping intervals → O(m)
// Step 3: Add remaining intervals → O(n − k − m)
// Total: O(n) — we process each interval once.

// Space Complexity
// We store results in a separate vector → O(n) extra space.
// If the output is allowed to overwrite the input (intervals), it could be O(1) extra space.

