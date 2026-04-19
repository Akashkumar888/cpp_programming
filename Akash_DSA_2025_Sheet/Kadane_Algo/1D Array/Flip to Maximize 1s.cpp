class Solution {
public:
    int maxOnes(vector<int>& arr) {
        int n = arr.size();
        // Step 1: Count original 1s
        int countOne = 0;
        for (int x : arr) {
            if (x == 1) countOne++;
        }
        // Step 2: Apply Kadane on transformed values
        int sum = 0;
        int maxGain = 0;  // IMPORTANT: start with 0 (no flip case)
        for (int i = 0; i < n; i++) {
            int val = (arr[i] == 0) ? 1 : -1;

            sum += val;
            maxGain = max(maxGain, sum);

            if (sum < 0) sum = 0;
        }
        // Step 3: Add gain to original ones
        return countOne + maxGain;
    }
};
