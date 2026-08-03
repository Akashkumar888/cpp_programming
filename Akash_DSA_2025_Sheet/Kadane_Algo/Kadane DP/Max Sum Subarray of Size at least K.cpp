
class Solution {
  public:
    int maxSumWithK(vector<int>& arr, int k) {
        int n = arr.size();
        vector<long long> maxEndHere(n);
        // Kadane DP
        maxEndHere[0] = arr[0];
        for(int i = 1; i < n; i++) {
            maxEndHere[i] = max((long long)arr[i], maxEndHere[i - 1] + arr[i]);
        }
        // First window of size k
        long long windowSum = 0;
        for(int i = 0; i < k; i++) windowSum += arr[i];
        long long ans = windowSum;
        for(int i = k; i < n; i++) {
            windowSum += arr[i];
            windowSum -= arr[i - k];
            ans = max(ans, windowSum);
            ans = max(ans, windowSum + maxEndHere[i - k]);
        }
        return (int)ans;
    }
};