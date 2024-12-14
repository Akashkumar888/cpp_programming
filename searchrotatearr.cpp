
#include <bits/stdc++.h>
using namespace std;

// Function to find the index of the smallest element (pivot) in the rotated sorted array
int rotate(vector<int>& arr) {
    int l = 0, r = arr.size() - 1;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] > arr[r]) l = mid + 1;
        else r = mid;
    }
    return r; // Pivot index
}

// Function to perform binary search
int binarysearch(int l, int r, vector<int>& arr, int target) {
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) l = mid + 1;
        else r = mid - 1;
    }
    return -1; // Target not found
}

// Main function to search for the target in the rotated sorted array
int search(vector<int>& arr, int key) {
    int pivot = rotate(arr); // Find the pivot
    // Apply binary search in the two segments
    int idx = binarysearch(0, pivot - 1, arr, key);
    if (idx != -1) return idx;
    return binarysearch(pivot, arr.size() - 1, arr, key);
}

int main() {
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
    int key = 6;
    int result = search(arr, key);
    if (result != -1) 
        cout << "Element " << key << " found at index " << result << endl;
    else 
        cout << "Element " << key << " not found in the array" << endl;
    return 0;
}
