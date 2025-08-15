
class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0)return false;
        // n == 4x.
        double num=log10(n)/log10(4);
        return int(num)==num;
    }
};

class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0) return false;
        
        // must be power of two
        if (__builtin_popcount(n) != 1) return false;

        // position of set bit (1-based from LSB)
        int pos = log2(n) + 1; 

        // power of four → set bit at odd position
        return (pos % 2 == 1);
    }
};


class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0) return false;
        int setbit = __builtin_popcount(n);
        if (setbit == 1) { // must be power of two
            int bits = floor(log2(n)) + 1; // position of MSB (1-based)
            if (bits%2 && (n>>bits-1)&1) return true; // odd position → power of four
        }
        return false;
    }
};
