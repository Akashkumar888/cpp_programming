
class Solution {
  public:
  // Check if we can select k elements with at least 'mid' difference
  bool isPossible(int n, vector<int>& arr, int mid, int k) {
      int count = 1;        // place first element
      int last = arr[0];    // last placed element
      for (int i = 1; i < n; i++) {
          if (arr[i] - last >= mid) {
              count++;
              last = arr[i];
              if (count >= k) return true; // placed all k elements
          }
      }
      return false;
  }

  // Main function: find maximum possible minimum difference
  int maxMinDiff(vector<int>& arr, int k) {
      int n = arr.size();
      sort(arr.begin(), arr.end());

      int l = 1;                  // minimum possible distance
      int r = arr[n - 1];         // maximum possible distance
      int ans = -1;

      while (l <= r) {
          int mid = l + (r - l) / 2;
          if (isPossible(n, arr, mid, k)) {
              ans = mid;          // feasible → try larger distance
              l = mid + 1;
          } else {
              r = mid - 1;        // not feasible → try smaller distance
          }
      }
      return ans;
  }
};

