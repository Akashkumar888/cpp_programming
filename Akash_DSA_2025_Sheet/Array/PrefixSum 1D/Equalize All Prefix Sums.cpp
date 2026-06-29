
class Solution {
  public:
    vector<int> optimalArray(vector<int> &arr) {
        int n = arr.size();
        vector<long long> prefix(n);
        prefix[0] = arr[0];
        for(int i = 1; i < n; i++) {
            prefix[i] = prefix[i-1] + arr[i];
        }
        vector<int> result(n);
        for(int i = 0; i < n; i++) {
            int mid = i / 2;
            long long left = 1LL * arr[mid] * (mid + 1) - prefix[mid];
            long long right = (prefix[i] - prefix[mid]) - 1LL * arr[mid] * (i - mid);
            result[i] = left + right;
        }
        return result;
    }
};