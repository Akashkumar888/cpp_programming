
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Function to find the minimum subarray length with bitwise AND >= k
int minimumSubarrayWithAND(vector<int>& nums, int k) {
    int n = nums.size();
    int minsize = INT_MAX;
    int i = 0, j = 0;
    int currentAND = nums[0];  // Initialize with the first element

    while (j < n) {
        // Compute AND over the window [i, j]
        currentAND &= nums[j];

        // Shrink the window from the left while AND >= k
        while (i <= j && currentAND >= k) {
            minsize = min(minsize, j - i + 1);
            currentAND &= ~nums[i];  // Remove nums[i] from the AND result
            i++;
        }

        j++;
        if (j < n) currentAND = nums[j];  // Start ANDing with the next element
    }

    return minsize == INT_MAX ? -1 : minsize;
}

int main() {
    // Example 1: nums = [8, 4, 2], k = 4
    vector<int> nums1 = {8, 4, 2};
    int k1 = 4;
    cout << "Minimum subarray length with AND >= 4: "
         << minimumSubarrayWithAND(nums1, k1) << endl;

    // Example 2: nums = [6, 2, 7], k = 2
    vector<int> nums2 = {6, 2, 7};
    int k2 = 2;
    cout << "Minimum subarray length with AND >= 2: "
         << minimumSubarrayWithAND(nums2, k2) << endl;

    return 0;
}
