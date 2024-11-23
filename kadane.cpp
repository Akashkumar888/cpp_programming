#include <bits/stdc++.h>
using namespace std;

// Function to find the maximum subarray sum
int maxSubarraySum(vector<int> &arr) {
    int sum = 0;
    int maxsum = INT_MIN;
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        sum += arr[i];
        maxsum = max(maxsum, sum);
        if (sum < 0) {
            sum = 0; // Reset sum if it becomes negative
        }
    }

    return maxsum;
}

int main() {
    vector<int> arr = {3, -2, 5, -1}; // Example array
    cout << "Maximum Subarray Sum is: " << maxSubarraySum(arr) << endl;
    return 0;
}
