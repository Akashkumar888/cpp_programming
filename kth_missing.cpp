
#include <bits/stdc++.h>
using namespace std;

int kthMissing(vector<int>& arr, int k) {
    int n = arr.size();
    int l = 0, r = n - 1;
    int ans = arr[n - 1] + k; // Default to the largest possible value
    while (l <= r) {
        int mid = l + (r - l) / 2;
        // Count of missing numbers till arr[mid]
        if (arr[mid] - mid - 1 < k) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return l + k; // Calculate the k-th missing number
}

int main() {
    // Input
    vector<int> arr = {2, 3, 4, 7, 11};
    int k = 5;

    // Function call
    cout << "The " << k << "-th missing positive number is: " << kthMissing(arr, k) << endl;

    return 0;
}
