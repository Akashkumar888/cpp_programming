
class Solution {
public:
    int gcd(int a, int b) {
        if (b == 0)return a;
        return gcd(b, a % b);
    }

    int lcm(int a, int b) {
        return (a / gcd(a, b)) * b;
    }
    int pairCount(int x, int y) {
        // LCM must be divisible by GCD
        if (y % x != 0) return 0;

        int z = y / x;

        // Count distinct prime factors of z
        int distinctPrimeFactors = 0;
        for (int p = 2; p * p <= z; p++) {
            if (z % p == 0) {
                distinctPrimeFactors++;
                while (z % p == 0) {
                    z /= p;
                }
            }
        }

        // If something greater than 1 remains,
        // it is another distinct prime factor.
        if (z > 1) distinctPrimeFactors++;

        // Number of ordered pairs = 2^k
        return 1 << distinctPrimeFactors;
    }
};