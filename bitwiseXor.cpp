
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Function to find the minimum subarray length with bitwise XOR >= k
int minimumSubarrayWithXOR(vector<int>& nums, int k) {
    int n = nums.size();
    int minsize = INT_MAX;
    int i = 0, j = 0;
    int currentXOR = 0;  // Initialize XOR as 0

    while (j < n) {
        // Compute XOR over the window [i, j]
        currentXOR ^= nums[j];

        // Shrink the window from the left while XOR >= k
        while (i <= j && currentXOR >= k) {
            minsize = min(minsize, j - i + 1);
            currentXOR ^= nums[i];  // Remove nums[i] from the XOR result
            i++;
        }

        j++;
    }

    return minsize == INT_MAX ? -1 : minsize;
}

int main() {
    // Example 1: nums = [3, 8, 2], k = 8
    vector<int> nums1 = {3, 8, 2};
    int k1 = 8;
    cout << "Minimum subarray length with XOR >= 8: "
         << minimumSubarrayWithXOR(nums1, k1) << endl;

    // Example 2: nums = [1, 2, 4], k = 6
    vector<int> nums2 = {1, 2, 4};
    int k2 = 6;
    cout << "Minimum subarray length with XOR >= 6: "
         << minimumSubarrayWithXOR(nums2, k2) << endl;

    return 0;
}
