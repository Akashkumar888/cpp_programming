
// 1) Greedy Interval Covering (your current method – optimized)
// This method converts each person into an interval and then greedily selects the minimum number of intervals to cover [0 … n-1].
// Idea
// For each index i:
// If arr[i] != -1 → interval is:
// L = max(0, i - arr[i])
// R = min(n-1, i + arr[i])
// We then apply a classic minimum interval covering greedy algorithm.
class Solution {
public:
    int minMen(vector<int>& arr) {
        int n = arr.size();

        // temp[l] = farthest right endpoint of any interval starting at l
        vector<int> temp(n, -1);

        // Step 1: Build intervals in compressed form
        for (int i = 0; i < n; i++) {
            if (arr[i] != -1) {
                int L = max(0, i - arr[i]);
                int R = min(n - 1, i + arr[i]);
                temp[L] = max(temp[L], R);
            }
        }

        int count = 0;
        int currEnd = -1;   // current coverage end
        int maxReach = -1; // best reachable end so far

        // Step 2: Greedy coverage from 0 to n-1
        for (int i = 0; i < n; i++) {
            maxReach = max(maxReach, temp[i]);

            if (currEnd < i) {   // need to choose a new worker
                if (maxReach < i) return -1; // cannot cover this hour

                currEnd = maxReach;
                count++;
            }
        }

        return count;
    }
};


// 2) Sorting Method (Classic Interval Scheduling)
// This is the more intuitive approach using sorting.
// Idea
// Convert each worker into an interval [L, R]
// Sort intervals by starting time.
// Greedily pick intervals that extend coverage the farthest.
class Solution {
public:
    int minMen(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int,int>> intervals;

        // Step 1: Build intervals
        for (int i = 0; i < n; i++) {
            if (arr[i] != -1) {
                int L = max(0, i - arr[i]);
                int R = min(n - 1, i + arr[i]);
                intervals.push_back({L, R});
            }
        }

        if (intervals.empty()) return -1;

        // Step 2: Sort by starting time
        sort(intervals.begin(), intervals.end());

        int count = 0;
        int idx = 0;
        int coveredTill = 0;

        // Step 3: Greedy selection
        while (coveredTill < n) {
            int farthest = coveredTill;

            // choose the interval with max R among those starting before or at coveredTill
            while (idx < intervals.size() && intervals[idx].first <= coveredTill) {
                farthest = max(farthest, intervals[idx].second + 1);
                idx++;
            }

            if (farthest == coveredTill) return -1; // stuck

            coveredTill = farthest;
            count++;
        }

        return count;
    }
};