#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxCircularSubarraySum(vector<int>& arr) {
    int n = arr.size();

    // Step 1: Find the maximum subarray sum using Kadane's algorithm
    int maxSum = INT_MIN, currentMax = 0;
    for (int num : arr) {
        currentMax = max(num, currentMax + num);
        maxSum = max(maxSum, currentMax);
    }

    // Step 2: Find the minimum subarray sum
    int minSum = INT_MAX, currentMin = 0, totalSum = 0;
    for (int num : arr) {
        currentMin = min(num, currentMin + num);
        minSum = min(minSum, currentMin);
        totalSum += num;
    }

    // Step 3: Handle the circular case
    int circularSum = totalSum - minSum;

    // Step 4: Edge case - If all numbers are negative
    if (maxSum < 0) {
        return maxSum; // All numbers are negative, so return the max (non-circular)
    }

    // Return the maximum of the two cases
    return max(maxSum, circularSum);
}

int main() {
    vector<int> arr = {5, -3, 5}; // Example input
    cout << "Maximum Circular Subarray Sum: " << maxCircularSubarraySum(arr) << endl;
    return 0;
}
