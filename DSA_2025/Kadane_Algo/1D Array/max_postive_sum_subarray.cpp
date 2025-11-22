
// max postive subarray sum
// Code 1 → maxSubArray
// This is Kadane’s Algorithm.
// It finds the maximum sum subarray (can include negatives if they increase the total sum).
// nums = [2, 3, 5, -2, 7, -4]
// Output → [2, 3, 5, -2, 7]  (sum = 15)
// Here, even though -2 is negative, it’s included because the total sum increases.
// ✅ Use when you want the maximum sum subarray (classic Kadane’s problem).


class Solution {
public:
    vector<int> maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int maxSum = INT_MIN;
        int start = 0;
        int bestStart = 0;
        int bestEnd = 0;

        for (int i = 0; i < n; i++) {
            if (sum == 0) start = i;   // potential start
            sum += nums[i];

            if (sum > maxSum) {
                maxSum = sum;
                bestStart = start;
                bestEnd = i;
            }

            if (sum < 0) sum = 0; // reset
        }

        // Extract subarray [ansStart ... ansEnd]
        vector<int> subArray(nums.begin() + bestStart, nums.begin() + bestEnd + 1);
        return subArray;
    }
};





