
class Solution {
  public:
// Definition recap
// A number is Happy if repeatedly replacing it with the sum of squares of its digits eventually leads to 1.
// Approach
// Start checking numbers from N+1
// For each number, check if it is a happy number
// The first happy number you find → return it
// How to check if a number is Happy
// Repeatedly compute sum of squares of digits
// If it becomes 1 → happy
// If it enters a loop (never reaches 1) → not happy
// Known fact: any non-happy number eventually falls into the cycle
// {4, 16, 37, 58, 89, 145, 42, 20}
// So we can stop when value ≤ 6 (except 1)

    int digitSquareSum(int n) {
        int sum = 0;
        while (n > 0) {
            int d = n % 10;
            sum += d * d;
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        while (n != 1 && n != 4) {   // 4 means cycle
            n = digitSquareSum(n);
        }
        return n == 1;
    }
    int nextHappy(int N) {
        int num = N + 1;
        while (true) {
            if (isHappy(num))return num;
            num++;
        }
    }
};
