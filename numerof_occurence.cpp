
#include <bits/stdc++.h>
using namespace std;

// Custom implementation of lower_bound
int lower_bound(vector<int>& arr, int target) {
    int n = arr.size();
    int l = 0, r = n - 1, idx = -1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == target) {
            idx = mid;  // Store the index
            r = mid - 1;  // Look for the first occurrence
        } else if (arr[mid] < target) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return idx;
}

// Custom implementation of upper_bound
int upper_bound(vector<int>& arr, int target) {
    int n = arr.size();
    int l = 0, r = n - 1, idx = -1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == target) {
            idx = mid;  // Store the index
            l = mid + 1;  // Look for the last occurrence
        } else if (arr[mid] < target) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return idx;
}

// Function to count frequency of a target in the array
int countFreq(vector<int>& arr, int target) {
    int idx1 = lower_bound(arr, target);
    int idx2 = upper_bound(arr, target);
    if (idx1 == -1 && idx2 == -1) return 0;  // Target not found
    return idx2 - idx1 + 1;  // Frequency of target
}

int main() {
    vector<int> arr = {1, 2, 2, 3, 3, 3, 4, 5};
    int target;
    cout << "Enter the target element: ";
    cin >> target;

    int frequency = countFreq(arr, target);
    if (frequency > 0)
        cout << "The element " << target << " appears " << frequency << " times." << endl;
    else
        cout << "The element " << target << " does not exist in the array." << endl;

    return 0;
}
