
class Solution {
  public:
    bool isSumOfConsecutive(int n) {
        // code here
        return n>0 && (n&(n-1) ) !=0;
    }
};

// ## Theory (Power of 2 Rule)

// To check if a number can be represented as a sum of consecutive positive numbers,
// use the power of 2 rule or math/coding approaches.

// The Quick Rule

// A number CANNOT be expressed as a sum of consecutive integers
// if it is exactly a power of 2.
// Example: 2, 4, 8, 16, 32, 64

// All other numbers can be expressed.

// ------------------------------------------------------------
// Method 1: Mathematical Logic (Odd Factors)
// ------------------------------------------------------------

// A mathematical theorem proves that the number of ways a positive integer
// can be written as the sum of consecutive numbers is:
//
// (Number of odd factors) - 1

// How to check:
//
// 1. Factorize the number N into its prime factors.
// 2. Identify all odd factors.
// 3. Subtract 1 from this count.

// Example:
//
// N = 15
//
// Odd factors = {1, 3, 5, 15}
//
// It can be represented as:
//
// 7 + 8 = 15
// 4 + 5 + 6 = 15
// 1 + 2 + 3 + 4 + 5 = 15

// Example:
//
// N = 8
//
// 8 = 2^3 (power of 2)
//
// Odd factors = {1}
//
// Ways = 1 - 1 = 0
//
// So it cannot be represented.

// ------------------------------------------------------------
// Method 2: Formula Check
// ------------------------------------------------------------

// Suppose:
//
// a + (a+1) + (a+2) + ... + (a+m-1) = N
//
// Formula:
//
// m/2 * [2a + (m-1)] = N
//
// To check:
//
// 1. Subtract:
//
// m*(m-1)/2
//
// from N
//
// 2. Check if:
//
// (N - m*(m-1)/2) % m == 0
//
// If divisible, a valid sequence exists.

// ------------------------------------------------------------
// Method 3: O(1) Power of 2 Rule in C++
// ------------------------------------------------------------

// If N is a power of 2 -> FALSE
// Otherwise -> TRUE

class Solution {
public:
bool isSumOfConsecutive(int n) {

```
    // number must be positive
    // if n is power of 2 => return false
    // otherwise return true

    return n > 0 && (n & (n - 1)) != 0;
}
```

};

// ------------------------------------------------------------
// Power of Two Check in C++
// ------------------------------------------------------------

// A number is power of 2 if it contains exactly one set bit.

class Solution {
public:
bool isPowerOfTwo(int n) {

```
    // n must be positive
    // n&(n-1) removes lowest set bit
    // if result becomes 0 => only one set bit existed

    return n > 0 && (n & (n - 1)) == 0;
}
```

};

// ------------------------------------------------------------
// Examples
// ------------------------------------------------------------

// N = 8
//
// Binary:
//
// 1000
//
// 8 & 7
//
// 1000
// 0111
// ----
// 0000
//
// Power of 2 => cannot be represented

// N = 15
//
// Binary:
//
// 1111
//
// 15 & 14
//
// 1111
// 1110
// ----
// 1110
//
// Not power of 2 => can be represented
