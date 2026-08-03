
class Solution {
  public:
    int findMax(int n, vector<int>& a, vector<int>& b, vector<int>& k) {
        vector<long long> diff(n + 1, 0);
        int m = a.size();
        // Build difference array
        for(int i = 0; i < m; i++) {
            diff[a[i]] += k[i];
            if(b[i] + 1 < n) diff[b[i] + 1] -= k[i];
        }
        long long currSum = 0;
        long long maxValue = 0;
        // Prefix sum gives final array values
        for(int i = 0; i < n; i++) {
            currSum += diff[i];
            maxValue = max(maxValue, currSum);
        }
        return (int)maxValue;
    }
};