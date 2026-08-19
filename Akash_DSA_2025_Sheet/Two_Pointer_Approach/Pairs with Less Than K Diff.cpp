
class Solution {
  public:
    int countPairs(vector<int>& arr, int k) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        long long count = 0;
        int i = 0;
        int j = 1;
        while (j < n) {
            // Difference is valid
            if (arr[j] - arr[i] < k) {
                count += (j - i);
                j++;
            }
            // Difference is too large
            else {
                i++;
                // Ensure j is always ahead of i
                if (i == j)j++;
            }
        }
        return count;
    }
};