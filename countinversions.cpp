

#include <iostream>
#include <vector>
using namespace std;

// Merges two sorted halves and counts inversions
int merge(int l, int mid, int r, vector<int>& arr) {
    vector<int> nums(r - l + 1);
    int i = l, j = mid + 1, idx = 0;
    int count = 0; // Initialize inversion count

    // Merge the two halves and count inversions
    while (i <= mid && j <= r) {
        if (arr[i] <= arr[j]) {
            nums[idx++] = arr[i++];
        } else {
            nums[idx++] = arr[j++];
            count += (mid - i + 1); // Count inversions
        }
    }

    // Copy remaining elements from left half
    while (i <= mid) {
        nums[idx++] = arr[i++];
    }

    // Copy remaining elements from right half
    while (j <= r) {
        nums[idx++] = arr[j++];
    }

    // Copy back the merged array into original array
    idx = 0;
    while (l <= r) {
        arr[l++] = nums[idx++];
    }

    return count;
}

// Merge Sort function that counts inversions
int mergeSort(int l, int r, vector<int>& arr) {
    int count = 0;
    if (l >= r) return count;

    int mid = l + (r - l) / 2;

    // Recursive calls to sort and count inversions
    count += mergeSort(l, mid, arr);
    count += mergeSort(mid + 1, r, arr);
    count += merge(l, mid, r, arr);

    return count;
}

// Function to calculate total inversion count
int inversionCount(vector<int>& arr) {
    return mergeSort(0, arr.size() - 1, arr);
}

// Driver code
int main() {
    vector<int> arr = {8, 4, 2, 1};
    cout << "Number of inversions: " << inversionCount(arr) << endl;
    return 0;
}