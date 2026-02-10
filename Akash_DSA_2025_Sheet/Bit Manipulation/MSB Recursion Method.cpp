
// 🔹 1️⃣ MSB Recursion Method (Divide by Highest Power of 2)
// Idea
// Find highest set bit (2^x)
// Count:
// Set bits till 2^x - 1
// MSB contribution from 2^x to n
// Recurse on remainder
// ✅ C++ Code (O(log n) time, O(log n) space)


class Solution {
  public:
    int countSetBits(int n) {
        if (n == 0) return 0;

        // highest set bit index
        int x = 31 - __builtin_clz(n);

        // set bits from 1 to (2^x - 1)
        int fullBlocks = x * (1 << (x - 1));

        // MSB contribution from 2^x to n
        int msbContribution = n - (1 << x) + 1;

        // remaining numbers
        int remainder = n - (1 << x);

        return fullBlocks + msbContribution + countSetBits(remainder);
    }
};