
class Solution {
public:
    int minProd(vector<int>& arr) {
        int n = arr.size();
        long long ans = LLONG_MAX;

        // Generate every non-empty subset
        for (int mask = 1; mask < (1 << n); mask++) {
            long long product = 1;
            for (int i = 0; i < n; i++) {
                // If ith bit is set, include arr[i]
                int ith_bit=mask & (1 << i);
                if (ith_bit) {
                    product *= arr[i];
                }
            }
            ans = min(ans, product);
        }
        return (int)ans;
    }
};