
class Solution {
  public:
    int kthSmallest(int m, int n, int k) {
        // code here
        int low = 1, high = m * n;
        while (low < high) {
            int mid = low + (high - low) / 2;
            int count = 0;

            // Count how many numbers are <= mid
            for (int i = 1; i <= m; ++i) {
                count += min(mid / i, n);
            }

            if (count < k) {
                low = mid + 1;  // kth number is larger
            } else {
                high = mid;     // kth number is ≤ mid
            }
        }
        return low;
    }
};