class Solution {
  public:
    int maxSubarrSum(vector<int>& arr, int a, int b) {
        // code here
        int n = arr.size();
        vector<int> prefix(n+1, 0);
        // Build prefix sum
        for (int i = 0; i < n; i++) {
            prefix[i+1] = prefix[i] + arr[i];
        }
        int maxSum = INT_MIN;
        multiset<int> s;  // store prefix values in valid window
        for (int j = 0; j <= n; j++) {
            // Remove prefix that is out of window (> b)
            if(j>b) {
                s.erase(s.find(prefix[j-b-1]));
            }
            // Add prefix[j-a] once it's valid
            if (j >= a) {
                s.insert(prefix[j-a]);
            }
            // Calculate answer
            if (!s.empty()) {
                maxSum = max(maxSum, (prefix[j] - *s.begin()));
            }
        }
        return maxSum;
    }
};