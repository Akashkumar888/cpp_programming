
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minRemoval(vector<vector<int>> &intervals) {
    int n = intervals.size();
    sort(intervals.begin(), intervals.end()); // Sort intervals by start time
    int cnt = 0;
    int i = 0, j = 1;

    while (j < n) {
        if (intervals[i][1] > intervals[j][0]) {
            // Overlap found
            cnt++;
            if (intervals[i][1] > intervals[j][1]) {
                i = j; // Retain the interval with the smaller end time
            }
        } else {
            i = j; // No overlap, move to the next interval
        }
        j++;
    }

    return cnt;
}

int main() {
    int n;
    cout << "Enter the number of intervals: ";
    cin >> n;

    vector<vector<int>> intervals(n, vector<int>(2));
    cout << "Enter the intervals (start end):\n";
    for (int i = 0; i < n; i++) {
        cin >> intervals[i][0] >> intervals[i][1];
    }

    int result = minRemoval(intervals);
    cout << "Minimum intervals to remove: " << result << endl;

    return 0;
}
