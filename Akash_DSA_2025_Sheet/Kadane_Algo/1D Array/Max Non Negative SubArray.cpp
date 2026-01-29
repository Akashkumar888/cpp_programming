
// Maximum Non-Negative Subarray

// Code 2 → maxNonNegativeSubarray
// It finds the maximum sum subarray consisting of only non-negative numbers.
// If two subarrays have the same sum, it picks the longer one.
// nums = [2, 3, 5, -2, 7, -4]
// Output → [2, 3, 5]  (sum = 10)
// Notice -2 breaks the streak → so [2,3,5] is chosen instead of including negatives.
// ✅ Use when negatives are not allowed in the subarray.

// find out the maximum sum sub-array of non negative numbers from A.
// The sub-array should be contiguous i.e., a sub-array created by choosing the second and fourth element and skipping the third element is invalid.
// Maximum sub-array is defined in terms of the sum of the elements in the sub-array.
// Find and return the required subarray.
// If there is a tie, then compare with segment's length and return segment which has maximum length.
// If there is still a tie, then return the segment with minimum starting index.


class Solution {
public:
    vector<int> maxNonNegativeSubarray(vector<int>& nums) {
        long long sum = 0;
        long long maxSum = -1;
        int start = 0;
        int bestStart = -1;
        int bestEnd = -1;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= 0) { // positive element hi lena hai 
                sum += nums[i];
                if (sum > maxSum || (sum == maxSum && (i - start) > (bestEnd - bestStart))) {
                    maxSum = sum;
                    bestStart = start;
                    bestEnd = i;
                }
            } 
            else {
                sum = 0;
                start = i + 1;
            }
        }

        if (bestStart == -1) return {};  // all negative

        return vector<int>(nums.begin() + bestStart, nums.begin() + bestEnd + 1);
    }
};


