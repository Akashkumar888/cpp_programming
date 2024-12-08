
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
    int n = arr.size();
    sort(arr.begin(), arr.end()); // Sort intervals by start time
    vector<vector<int>> ans;
    ans.push_back(arr[0]);

    for (int i = 1; i < n; i++) {
        if (ans.back()[1] >= arr[i][0]) {
            // Merge intervals
            ans.back()[0] = min(ans.back()[0], arr[i][0]);
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
        } else {
            // Add non-overlapping interval
            ans.push_back({arr[i][0], arr[i][1]});
        }
    }
    return ans;
}

int main() {
    int n;
    cout << "Enter the number of intervals: ";
    cin >> n;

    vector<vector<int>> intervals(n, vector<int>(2));
    cout << "Enter the intervals (start and end separated by space):\n";
    for (int i = 0; i < n; i++) {
        cin >> intervals[i][0] >> intervals[i][1];
    }

    vector<vector<int>> result = mergeOverlap(intervals);

    cout << "Merged Intervals:\n";
    for (const auto& interval : result) {
        cout << "[" << interval[0] << ", " << interval[1] << "]\n";
    }

    return 0;
}
