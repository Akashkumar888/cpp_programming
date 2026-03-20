class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0)return 1;
        int bits=floor(log2(n)) + 1;
        for(int kth_bits=0;kth_bits<bits;kth_bits++){
            n= n ^ (1<<kth_bits);// Toggle  kth_bits
        }
        return n;
    }
};


class Solution {
public:
    int bitwiseComplement(int n) {
        long long bits=floor(log2(n)) + 1;
        int mask=(1<<bits) - 1;// when we need numbers of setbit of bits size 
        //int mask=pow(2,bits) - 1;
        return mask ^ n;
    }
};

class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0)return 1;
        int mask = 0;
        while(mask < n){
            mask = (mask << 1) | 1;
        }
        return mask ^ n;
    }
};


// If you want a k-bit zero mask while constructing it
// You can do:
// int mask = 0;
// for(int i = 0; i < k; i++){
//     mask = mask << 1;
// }

// Result:
// k = 4
// mask progression
// 0
// 00
// 000
// 0000

// But the result is still 0.
// If your goal is k-bit range but all zero initially
// Use:
// int mask = 0;
// Because integer bits are already zero initialized.
