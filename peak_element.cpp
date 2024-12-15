
#include <vector>
#include <iostream>
using namespace std;

int findPeakElement(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        
        // Compare middle element with its right neighbor
        if (nums[mid] > nums[mid + 1]) {
            // Peak lies in the left half (including mid)
            right = mid;
        } else {
            // Peak lies in the right half (excluding mid)
            left = mid + 1;
        }
    }
    
    // 'left' and 'right' converge to the peak element
    return left;
}

int main() {
    vector<int> nums = {1, 2, 3, 1}; // Example input
    cout << "Peak Element Index: " << findPeakElement(nums) << endl;
    return 0;
}
