
class Solution {
  public:
    int MOD = 1e9 + 7;
    int palindromicStrings(int n, int k) {
        // perm = P(k, t)
        // Number of ways to choose and arrange
        // t different characters
        long long perm = 1;
        long long ans = 0;

        // t = 0
        // Odd length = 1
        //
        // Example:
        // "a", "b", ...
        //
        // k choices for center
        if(n >= 1){
            ans = k;
        }

        for(int t = 1; t <= k; t++){
            // P(k,t)
            perm = (perm * (k - t + 1)) % MOD;

            // ------------------------------------------------
            // Even length = 2*t
            // ------------------------------------------------
            if(2 * t <= n){
                ans = (ans + perm) % MOD;
            }
            // ------------------------------------------------
            // Odd length = 2*t + 1
            // ------------------------------------------------
            if(2 * t + 1 <= n && t < k){
                long long ways = (perm * (k - t)) % MOD;
                ans = (ans + ways) % MOD;
            }
        }
        return ans;
    }
};