
class Solution {
  public:
//   ✅ Correct way (minimum DP, interview-standard)
// Idea
// For every index:
// keep[i] → max subarray sum ending at i (no deletion)
// skip[i] → max subarray sum ending at i (one deletion allowed)
// Formula
// keep[i] = max(arr[i], keep[i-1] + arr[i])
// skip[i] = max(skip[i-1] + arr[i], keep[i-1])  // delete arr[i]
    int maxSumSubarray(vector<int>& arr) {
        // Code here
        int n = arr.size();
        int keep = arr[0];      // no deletion
        int skip = 0;           // one deletion
        int ans = arr[0];
        for (int i = 1; i < n; i++) {
            skip = max(skip + arr[i], keep); // delete current
            keep = max(arr[i], keep + arr[i]);
            ans = max(ans, max(keep, skip));
        }
        return ans;
    }
};