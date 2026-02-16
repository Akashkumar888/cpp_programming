class Solution {
public:
    int reverseBits(int n) {
        int leftMSB = 31;
        int rightLSB = 0;

        while (leftMSB > rightLSB) {

            int leftBit = (n >> leftMSB) & 1;
            int rightBit = (n >> rightLSB) & 1;

            if (leftBit != rightBit) {

                // Toggle both bits
                n = n ^ (1 << leftMSB);
                n = n ^ (1 << rightLSB);
            }

            leftMSB--;
            rightLSB++;
        }

        return n;
    }
};
// ✅ Correct Way: Clear & Set Bits Properly
// To modify a specific bit:
// 1️⃣ What is Toggle?
// Toggle means:
0 → 1
1 → 0
// 2️⃣ What is Flip?
// Flip and Toggle mean the SAME thing.
// There is no difference.
// Flip = Toggle = Invert bit

// 🔹 Clear bit at position pos
// n &= ~(1 << pos);

// 🔹 Set bit at position pos
// n |= (1 << pos);




class Solution {
public:
    int reverseBits(int n) {
        int num=0; //00000000000000000000000000000000
        for(int bit=0;bit<32;bit++){
            int rev=(32-bit-1);
            if((1<<bit)&n)num=(num)|(1<<rev);
        }
        return num;
    }
};

class Solution {
public:
    int reverseBits(int n) {
        int num=0; //00000000000000000000000000000000
        for(int bit=0;bit<32;bit++){
            int rev=(31-bit);
            if((1<<bit)&n)num=(num)|(1<<rev);
        }
        return num;
    }
};


class Solution {
public:
    int reverseBits(int n) {
    unsigned int num = 0;
    for(int i=0; i<32; i++) {
        num <<= 1;           // shift left
        num |= (n & 1);      // add last bit of n
        n >>= 1;             // shift n right
    }
    return num;
}
};


class Solution {
public:
    int reverseBits(int n) {
        return __builtin_bitreverse32(n);
    }
};

// 🚀 2️⃣ MOST OPTIMIZED (Bit Manipulation Trick — No Loop)
// If function is called MANY times, we use bit masks and divide & conquer.
// This method swaps:
// 16-bit halves
// 8-bit blocks
// 4-bit blocks
// 2-bit blocks
// 1-bit blocks
// 💎 Most Optimized Code

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {

        // swap 16-bit halves
        n = (n >> 16) | (n << 16);

        // swap 8-bit blocks
        n = ((n & 0xff00ff00) >> 8) | 
            ((n & 0x00ff00ff) << 8);

        // swap 4-bit blocks
        n = ((n & 0xf0f0f0f0) >> 4) | 
            ((n & 0x0f0f0f0f) << 4);

        // swap 2-bit blocks
        n = ((n & 0xcccccccc) >> 2) | 
            ((n & 0x33333333) << 2);

        // swap individual bits
        n = ((n & 0xaaaaaaaa) >> 1) | 
            ((n & 0x55555555) << 1);

        return n;
    }
};

// 🏆 3️⃣ If Called Many Times (Best Interview Answer)
// If function is called thousands/millions of times:
// ✅ Use Precomputation (Lookup Table)
// Idea:
// Reverse 8-bit numbers once
// Store in array of size 256
// Reverse 32-bit number using 4 lookups
// 💎 Ultra Optimized Version (Lookup Table)
class Solution {
private:
    uint32_t table[256];

    void buildTable() {
        for (int i = 0; i < 256; i++) {
            uint32_t x = i;
            uint32_t rev = 0;
            for (int j = 0; j < 8; j++) {
                rev = (rev << 1) | (x & 1);
                x >>= 1;
            }
            table[i] = rev;
        }
    }

public:
    Solution() {
        buildTable();
    }

    uint32_t reverseBits(uint32_t n) {
        return (table[n & 0xff] << 24) |
               (table[(n >> 8) & 0xff] << 16) |
               (table[(n >> 16) & 0xff] << 8) |
               (table[(n >> 24) & 0xff]);
    }
};
