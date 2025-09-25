
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

