class Solution {
  public:
  // check if we can achieve median >= mid
  bool isPossible(int n, vector<int>& arr, long long mid, long long k) {
      long long need = 0;
      int half = n / 2;
      if (n % 2) { // odd
          need += max(0LL, mid - (long long)arr[half]);
      } 
      else { // even → need to make average ≥ mid
          need += max(0LL, 2 * mid - ((long long)arr[half] + arr[half - 1]));
      }
      for (int i = half + 1; i < n; i++) {
          need += max(0LL, mid - (long long)arr[i]);
          if (need > k) return false; // early stop
      }
      return need <= k;
  }

  int maximizeMedian(vector<int>& arr, int k) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        long long l = arr[0];// without k operations 
        long long r = arr[n - 1] + k; // after k operations 
        long long maxMedian = l;
        while (l <= r) {
            long long mid = l + (r - l) / 2;
            if (isPossible(n, arr, mid, k)) {
                maxMedian = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return int(maxMedian);
  }
};

// ⏱ Time Complexity
// sort(arr.begin(), arr.end()) → O(n log n)
// Binary search loop:
// Search range is up to k + max(arr) → ~ O(log k) iterations.
// Each iteration calls isPossible(), which in the worst case scans n/2 elements → O(n).
// So binary search phase: O(n log k)
// 👉 Total time complexity = O(n log n + n log k)
// For large n (up to 1e5) and k (up to 1e9), this is efficient.

// 💾 Space Complexity
// Sorting: O(1) extra (if we use in-place sort like std::sort).
// A few long long variables: O(1).
// 👉 Total space complexity = O(1) (excluding input array storage).

