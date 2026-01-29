
class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        // Code here
    int n = arr.size();
    unordered_map<int, int> firstIndex;
    int maxLen = 0, sum = 0;

    for (int i = 0; i < n; ++i) {
        // Map values: +1 if > k, -1 if <= k
        if (arr[i] > k) sum += 1;
        else sum -= 1;

        // Entire subarray from 0 to i is valid
        if (sum > 0) {
            maxLen = i + 1;
        } else {
            // Check if there's a prefix sum that allows a valid subarray
            if (firstIndex.find(sum - 1) != firstIndex.end()) {
                maxLen = max(maxLen, i - firstIndex[sum - 1]);
            }
        }
        if (firstIndex.find(sum) == firstIndex.end()) {
            firstIndex[sum] = i;
        }
    }
    return maxLen;
    }
  };

  