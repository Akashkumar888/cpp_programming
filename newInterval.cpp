
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> insertInterval(vector<vector<int>> &intervals, vector<int> &newInterval) {
    vector<vector<int>> ans;
    int n = intervals.size();
    int i = 0;

    // Step 1: Add all intervals that come before the newInterval (non-overlapping)
    while (i < n && intervals[i][1] < newInterval[0]) {
        ans.push_back(intervals[i]);
        i++;
    }

    // Step 2: Merge overlapping intervals with newInterval
    while (i < n && intervals[i][0] <= newInterval[1]) {
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i][1]);
        i++;
    }
    // Add the merged interval
    ans.push_back(newInterval);

    // Step 3: Add remaining intervals that come after the newInterval (non-overlapping)
    while (i < n) {
        ans.push_back(intervals[i]);
        i++;
    }

    return ans;
}

int main() {
    int n; // Number of intervals
    cout << "Enter the number of intervals: ";
    cin >> n;

    vector<vector<int>> intervals(n, vector<int>(2));
    cout << "Enter the intervals (start end):\n";
    for (int i = 0; i < n; i++) {
        cin >> intervals[i][0] >> intervals[i][1];
    }

    vector<int> newInterval(2);
    cout << "Enter the new interval (start end): ";
    cin >> newInterval[0] >> newInterval[1];

    vector<vector<int>> result = insertInterval(intervals, newInterval);

    cout << "Merged Intervals:\n";
    for (const auto &interval : result) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;

    return 0;
}

