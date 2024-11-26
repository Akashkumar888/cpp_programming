#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int circularSubarraySum(vector<int> &arr) {
    int n = arr.size();
    int maxsum = INT_MIN; 
    int minsum = INT_MAX; 
    int sum1 = 0, sum2 = 0; 
    int total = 0; 

    for (int i = 0; i < n; i++) {
        total += arr[i];  // Total sum of array
        sum2 += arr[i];   // Running sum for max subarray
        sum1 += arr[i];   // Running sum for min subarray

        if (sum2 < 0) sum2 = 0;  // Reset max subarray if negative
        if (sum1 > 0) sum1 = 0;  // Reset min subarray if positive

        maxsum = max(sum2, maxsum);  // Update max subarray sum
        minsum = min(sum1, minsum);  // Update min subarray sum
    }

    if (maxsum < 0) return maxsum;  // If all numbers are negative, return maxsum
    return max(maxsum, total - minsum);  // Return the best of circular and non-circular cases
}

int main() {
    vector<int> arr = {8, -4, 3, -5, 4};  // Example input
    cout << "Maximum Circular Subarray Sum: " << circularSubarraySum(arr) << endl;
    return 0;
}
