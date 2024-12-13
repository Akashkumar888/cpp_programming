#include <bits/stdc++.h>
using namespace std;

// Function to find the pivot (minimum element) in a rotated sorted array
int rotate(vector<int>& arr) {
    int l = 0, r = arr.size() - 1;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] > arr[r]) {
            l = mid + 1;  // Minimum is in the right part
        } else {
            r = mid;  // Minimum is in the left part
        }
    }
    return r;  // Index of the smallest element
}

// Function to find the minimum element
int findMin(vector<int>& arr) {
    int pivot = rotate(arr);  // Find the pivot point
    return arr[pivot];  // Minimum element
}

int main() {
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};  // Example rotated array
    cout << "The minimum element is: " << findMin(arr) << endl;
    return 0;
}
