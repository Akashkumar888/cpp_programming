#include <iostream>
#include <vector>
#include <algorithm> // For reverse and swap functions

using namespace std;

int main() {
    vector<int> arr = {1, 2, 3}; // Example input
    int n = arr.size();
    int idx = -1;

    // Step 1: Find the first decreasing element from the end
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] < arr[i + 1]) {
            idx = i;
            break;
        }
    }

    // Step 2: If such an element exists, find the smallest element larger than arr[idx] to the right
    if (idx != -1) {
        for (int i = n - 1; i > idx; i--) {
            if (arr[i] > arr[idx]) {
                swap(arr[i], arr[idx]); // Swap the two elements
                break;
            }
        }
    }

    // Step 3: Reverse the subarray to the right of idx
    reverse(arr.begin() + idx + 1, arr.end());

    // Output the result
    cout << "Next permutation: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
