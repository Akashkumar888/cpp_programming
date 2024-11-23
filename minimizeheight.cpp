
#include <bits/stdc++.h>
using namespace std;

// Function to minimize the difference
int getMinDiff(vector<int> &arr, int k) {
    int n = arr.size();
    sort(arr.begin(), arr.end());
    int ans = arr[n - 1] - arr[0]; // Initial difference between max and min

    for (int i = 1; i < n; i++) {
        // Skip if decreasing height leads to a negative value
        if (arr[i] - k < 0) continue;

        // Calculate the new minimum and maximum
        int leftmin = min(arr[0] + k, arr[i] - k);
        int rightmax = max(arr[n - 1] - k, arr[i - 1] + k);

        // Update the answer with the minimum difference
        ans = min(ans, rightmax - leftmin);
    }

    return ans;
}

int main() {
    // Input array and K
    int n, k;
    cout << "Enter the number of towers: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the heights of the towers: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the value of K: ";
    cin >> k;

    // Compute and display the result
    int result = getMinDiff(arr, k);
    cout << "The minimum difference is: " << result << endl;

    return 0;
}
