
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to check if it is possible to place 'k' cows with minimum distance 'mid'
bool valid(vector<int>& arr, int mid, int k) {
    int n = arr.size();
    int cnt = 1, prev = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] - prev >= mid) {
            prev = arr[i];
            cnt++;
        }
    }
    return cnt >= k;
}

// Function to solve the Aggressive Cows problem
int aggressiveCows(vector<int>& arr, int k) {
    int n = arr.size();
    sort(arr.begin(), arr.end());
    int l = 0, r = arr[n - 1] - arr[0], ans = 0;

    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (valid(arr, mid, k)) {
            ans = max(ans, mid);
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return ans;
}

int main() {
    int n, k;
    cout << "Enter the number of stalls (n): ";
    cin >> n;

    vector<int> stalls(n);
    cout << "Enter the stall positions: ";
    for (int i = 0; i < n; i++) {
        cin >> stalls[i];
    }

    cout << "Enter the number of cows (k): ";
    cin >> k;

    int result = aggressiveCows(stalls, k);
    cout << "The largest minimum distance is: " << result << endl;

    return 0;
}
