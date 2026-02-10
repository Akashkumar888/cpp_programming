
// Kernighan’s Algorithm (Counting Set Bits)
// Idea
// Kernighan’s Algorithm efficiently counts the number of set bits (1s) in a binary number by removing the rightmost set bit in each step.
// Key Observation
// n - 1 flips all bits after the rightmost set bit (including that bit).
// n & (n - 1) clears the rightmost set bit of n.
// Each iteration removes exactly one set bit.
// So, number of iterations = number of set bits.

// Algorithm Steps
// Initialize count = 0.
// While n != 0:
// Update n = n & (n - 1) (removes rightmost set bit).
// Increment count.
// Return count.

class Solution {
  public:
    int setBits(int n) {
        // Write Your Code here
        int count = 0;
        // Runs till n becomes 0
        while (n>0) {
            // Turn off/reset the rightmost set bit
            n &= (n - 1);
            // Increment the count of set bits
            count++;
        }
        return count;
    }
};
