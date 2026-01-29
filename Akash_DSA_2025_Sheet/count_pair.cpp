
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to count pairs with sum less than the target
int countPairs(vector<int> &arr, int target) {
    int n = arr.size();
    sort(arr.begin(), arr.end()); // Sort the array
    int count = 0;
    int l = 0, r = n - 1;

    while (l < r) {
        if (arr[l] + arr[r] < target) {
            count += (r - l); // All pairs from l to r are valid
            l++; // Move left pointer forward
        } else {
            r--; // Move right pointer backward
        }
    }

    return count;
}

int main() {
    // Test input
    vector<int> arr = {1, 2, 3, 4, 5};
    int target = 8;

    // Function call
    int result = countPairs(arr, target);

    // Output the result
    cout << "Number of pairs with sum less than " << target << ": " << result << endl;

    return 0;
}
