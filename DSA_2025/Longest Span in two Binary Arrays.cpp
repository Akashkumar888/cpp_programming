class Solution {
  public:
    int longestCommonSum(vector<int> &a1, vector<int> &a2) {
        int n = a1.size();
        // Step 1: Create a difference array where:
        // diff[i] = a1[i] - a2[i]
        // Goal: Find longest subarray where sum of differences is 0
        //       => a1[i..j] == a2[i..j]
        vector<int> diff(n);
        for (int i = 0; i < n; i++) {
            diff[i] = a1[i] - a2[i];
        }
        unordered_map<int, int> mp; // To store (cumulative sum → first index)
        int CumSum = 0;             // Cumulative sum of the diff array
        int maxlen = 0;             // Stores length of the longest subarray

        for (int i = 0; i < n; i++) {
            CumSum += diff[i]; // Update cumulative sum

            if (CumSum == 0) {
                // Subarray from index 0 to i has equal sum in both arrays
                maxlen = i + 1;
            }
            // If this CumSum has been seen before, that means the subarray
            // between previous index+1 and current index has net sum = 0
            if (mp.find(CumSum) != mp.end()) {
                maxlen = max(maxlen, i - mp[CumSum]);
            } 
            else {
                // Store the first occurrence of this CumSum
                mp[CumSum] = i;
            }
        }
        return maxlen;
    }
};

