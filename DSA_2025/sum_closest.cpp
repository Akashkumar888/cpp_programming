
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// Function to find the pair with the closest sum to the target
vector<int> sumClosest(vector<int>& arr, int target) {
    int n = arr.size();
    sort(arr.begin(), arr.end()); // Sort the array
    int i = 0, j = n - 1;
    int closest = INT_MAX, p1 = -1, p2 = -1;

    while (i < j) {
        int sum = arr[i] + arr[j];           // Sum of the pair
        int diff = abs(target - sum);        // Absolute difference from the target

        // Update closest pair based on conditions
        if (diff < closest || (diff == closest && (arr[j] - arr[i]) > (p2 - p1))) {
            closest = diff;
            p1 = arr[i];
            p2 = arr[j];
        }

        // Adjust pointers based on the current sum
        if (sum < target) {
            i++;
        } else {
            j--;
        }
    }

    if (p1 == -1 && p2 == -1) return {}; // No valid pair found
    return {p1, p2};                     // Return the closest pair
}

// Main function for testing
int main() {
    vector<int> arr = {1, 3, 4, 7, 10}; // Test array
    int target = 8;                     // Test target

    vector<int> result = sumClosest(arr, target);

    // Display result
    if (result.empty()) {
        cout << "No valid pair found!" << endl;
    } else {
        cout << "Closest pair: [" << result[0] << ", " << result[1] << "]" << endl;
    }

    return 0;
}
