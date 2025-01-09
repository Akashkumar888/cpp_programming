
#include <iostream>
#include <vector>
using namespace std;

vector<int> subarraySum(vector<int> &arr, int target) {
    // Size of the array
    int n = arr.size();

    // Variables to keep track of the current sum and window pointers
    int sum = 0;
    int i = 0, j = 0;

    // Indices for the result (1-based indexing)
    int idx1 = -1, idx2 = -1;

    // Two-pointer approach
    while (j < n) {
        // Add the current element to the sum
        sum += arr[j];

        // Shrink the window if the sum exceeds the target
        while (sum > target) {
            sum -= arr[i];
            i++;
        }

        // Check if the current sum equals the target
        if (sum == target) {
            idx1 = i + 1;  // Convert to 1-based index
            idx2 = j + 1;  // Convert to 1-based index
            break;         // Exit once the subarray is found
        }

        // Expand the window
        j++;
    }

    // If no subarray is found, return {-1}
    if (idx1 == -1 && idx2 == -1) return {-1};

    // Return the 1-based indices of the subarray
    return {idx1, idx2};
}

int main() {
    int n, target;

    // Input the size of the array
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);

    // Input the array elements
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Input the target sum
    cout << "Enter the target sum: ";
    cin >> target;

    // Call the function
    vector<int> result = subarraySum(arr, target);

    // Output the result
    if (result.size() == 1 && result[0] == -1) {
        cout << "No subarray found." << endl;
    } else {
        cout << "Subarray found from index " << result[0] << " to " << result[1] << endl;
    }

    return 0;
}
