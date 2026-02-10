
// 🔹 2️⃣ Bit Cycle Contribution Method
// Idea
// Each bit follows a repeating pattern of 0s and 1s
// Count how many times each bit is ON from 1..n
// ✅ C++ Code (O(log n) time, O(1) space)


class Solution {
  public:
    int countSetBits(int n) {
        long long ans = 0;

        for (int i = 0; (1LL << i) <= n; i++) {
            long long cycle = 1LL << (i + 1);
            long long half  = 1LL << i;

            long long fullCycles = n / cycle;
            ans += fullCycles * half;

            long long rem = n % cycle;
            ans += max(0LL, rem - half + 1);
        }

        return ans;
    }
};