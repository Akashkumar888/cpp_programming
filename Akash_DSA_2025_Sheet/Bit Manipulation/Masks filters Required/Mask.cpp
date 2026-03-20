
// 1️⃣ What is a Mask?
// A mask is a number whose bits are arranged so that when you apply a bitwise operation (&, |, ^, ~), it selects, clears, toggles, or limits certain bits.

// Examples:

// Mask	Purpose
// 1<<k	isolate the k-th bit
// (1<<k)-1	lower k bits all 1
// ~0	all bits 1
// mask ^ n	flip bits where mask has 1
// 2️⃣ How to Recognize When a Mask Is Needed

// Usually masks appear when the problem asks things like:
// Pattern 1 — Flip bits
// Keywords:
// complement
// toggle
// invert bits
// Example problems:
// Number Complement
// Minimum K Consecutive Bit Flips
// Flip Bit to Win
// Typical mask pattern:
// mask ^ n
// Example:

// 111 ^ 101 = 010
// Pattern 2 — Extract specific bits

// Keywords:
// check kth bit
// isolate bits
// last k bits
// Mask:
// n & (1<<k)
// Example

// n = 13 = 1101
// check bit 2

// 1101
// 0100
// ----
// 0100
// If result ≠ 0 → bit is set.
// Pattern 3 — Clear specific bits
// Keywords:
// remove bit
// unset bit
// Mask:
// n & ~(1<<k)
// Example
// n = 1101
// mask = ~(0100)
// 1101
// 1011
// ----
// 1001
// Pattern 4 — Set a bit
// Keywords:
// turn on bit
// ensure bit is 1
// Mask:
// n | (1<<k)
// Pattern 5 — Create k bits of 1
// Keywords:
// limit bits
// lower bits
// complement only within size
// Mask:
// (1<<k) - 1
// Example
// k = 4
// mask = 1111
// Used in your problem.
// Pattern 6 — Range mask
// Example:
// Extract bits between i and j
// Mask pattern:
// ((1<<(j-i+1))-1) << i

// 3️⃣ Your Problem Pattern
// Your code:
// mask = 111...
// return mask ^ n;
// Pattern:
// Flip only the bits that exist in n
// Example
// n = 101
// mask = 111
// Without mask:
// ~101 = 111111111111010
// Mask limits complement to valid bits.

// 4️⃣ Quick Decision Guide
// When reading a problem, ask:
// Q1
// Are we checking a bit?
// Use
// n & (1<<k)
// Q2
// Are we setting a bit?
// Use
// n | (1<<k)
// Q3
// Are we clearing a bit?
// Use
// n & ~(1<<k)
// Q4
// Are we flipping bits?
// Use
// n ^ mask
// Q5
// Are we limiting bits to k size?
// Use
// (1<<k) - 1
// 5️⃣ Classic Bit Mask Problems (Important)
// Practice these — they train mask recognition.
// Easy
// Number Complement
// Counting Bits
// Power of Two
// Single Number
// Medium
// Subsets (bitmasking)
// Maximum XOR of two numbers
// Find Missing Number
// Hard
// Minimum K Consecutive Bit Flips
// Maximum XOR Subarray
// Traveling Salesman (DP + bitmask)

// 6️⃣ Golden Rule for Masks
// Think of masks as filters:
// Operation	Meaning
// & mask	keep selected bits
// `	mask`
// ^ mask	toggle bits
// ~mask	invert mask

// 7️⃣ Example Recognition
// Problem:
// flip only existing bits
// Recognize:
// mask = (1<<bits)-1
// answer = mask ^ n
// ✅ Your thinking is already correct:
// “mask is used where operations must be applied only to certain bits.”
// Exactly right.