
// User function Template for C++

class Solution {
  public:
// The n-th magic number is formed by summing unique powers of 5 according to the binary digits of n:
// If n in binary is b_k b_{k-1} ... b_1 b_0 (LSB = b_0), then
//   Examples:
// n=1 (binary 1) → 5^1 = 5
// n=2 (binary 10) → 5^2 = 25
// n=3 (binary 11) → 5^2 + 5^1 = 30
// n=4 (binary 100) → 5^3 = 125
//   Example checks
// n = 1 → 5
// n = 2 → 25
// n = 3 → 30
// n = 5 → 130 (binary 101 → 5^3 + 5^1 = 125 + 5)
  long long MOD=1e9+7;
    long long int nthMagicNo(int n) {
        // complete the function here
        long long ans = 0;
        long long pow5 = 5 % MOD;      // corresponds to 5^(i+1) for i = 0 initially
        while (n > 0) {
            if (n & 1LL) {
                ans = (ans + pow5) % MOD;
            }
            n >>= 1;
            // advance pow5 to next power: multiply by 5
            pow5 = (pow5 * 5) % MOD;
        }
        return ans;
    }
};