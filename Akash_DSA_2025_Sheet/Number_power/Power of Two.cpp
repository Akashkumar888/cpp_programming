
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0)return false;
        return __builtin_popcount(n)==1;
    }
};

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0)return false;
        double num=log10(n)/log10(2);
        return int(num)==num;
    }
};

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n>0 && (n&(n-1) ) ==0;
    }
};

// it checks power of two also  (n&(n-1) ) ==0;

## Method 1: Using Builtin Popcount

// Theory:
//
// A power of 2 always contains exactly one set bit.
//
// Example:
//
// 2  = 0010
// 4  = 0100
// 8  = 1000
// 16 = 10000
//
// Since only one bit is set,
// __builtin_popcount(n) == 1

```cpp
class Solution {
public:
    bool isPowerOfTwo(int n) {

        // negative and zero are not power of 2
        if(n<=0) return false;

        // count set bits
        // if exactly one set bit exists => power of 2
        return __builtin_popcount(n)==1;
    }
};
```

// Time Complexity: O(1)
// Space Complexity: O(1)

// ------------------------------------------------------------
// Method 2: Using Logarithm
// ------------------------------------------------------------

// Theory:
//
// If n is power of 2:
//
// n = 2^x
//
// Taking log:
//
// x = log2(n)
//
// If x is integer,
// then n is power of 2.
//
// Example:
//
// n = 8
//
// log2(8) = 3
//
// integer => true
//
// n = 10
//
// log2(10) = 3.32
//
// not integer => false

```cpp
class Solution {
public:
    bool isPowerOfTwo(int n) {

        // negative and zero are invalid
        if(n<=0) return false;

        // log10(n)/log10(2) = log2(n)
        double num=log10(n)/log10(2);

        // check if integer
        return int(num)==num;
    }
};
```

// Time Complexity: O(1)
// Space Complexity: O(1)

// ------------------------------------------------------------
// Method 3: Bit Manipulation (Best Method)
// ------------------------------------------------------------

// Theory:
//
// Power of 2 contains exactly one set bit.
//
// Trick:
//
// n & (n-1)
//
// removes the lowest set bit.
//
// Example:
//
// n = 8
//
// Binary:
//
// 1000
//
// n-1 = 7
//
// 0111
//
// AND:
//
// 1000
// 0111
// ----
// 0000
//
// Result becomes 0
// because only one set bit existed.
//
// Example:
//
// n = 10
//
// Binary:
//
// 1010
//
// n-1 = 9
//
// 1001
//
// AND:
//
// 1010
// 1001
// ----
// 1000
//
// Not zero
// because more than one set bit existed.
//
// Therefore:
//
// if (n & (n-1)) == 0
//
// then n is power of 2.

```cpp
class Solution {
public:
    bool isPowerOfTwo(int n) {

        // n must be positive
        // remove lowest set bit
        // if result becomes 0 => only one set bit existed

        return n > 0 && (n & (n - 1)) == 0;
    }
};
```

// Time Complexity: O(1)
// Space Complexity: O(1)

// ------------------------------------------------------------
// Why (n & (n-1)) Works?
// ------------------------------------------------------------

// Property:
//
// n-1 flips bits after the rightmost set bit.
//
// Example:
//
// n = 16
//
// Binary:
//
// 10000
//
// n-1:
//
// 01111
//
// AND:
//
// 10000
// 01111
// -----
// 00000
//
// Result = 0
//
// Since only one set bit existed,
// it is power of 2.
