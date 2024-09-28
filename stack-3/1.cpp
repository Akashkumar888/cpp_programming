
#include <vector>
#include <algorithm> // For std::max

using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> ans;
    if (n == 0 || k == 0) return ans; // Handle edge cases

    for (int i = 0; i < n - k+1; i++) { // Loop through each window
        int maxi = nums[i]; // Initialize maxi for the current window
        for (int j = i; j < i + k; j++) { // Loop through elements in the current window
            maxi = max(maxi, nums[j]); // Update maxi if we find a greater value
        }
        ans.push_back(maxi); // Store the maximum for the current window
    }
    return ans;
}
