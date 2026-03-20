
class Solution {
public:
    int findComplement(int num) {
        int bits=floor(log2(num)) + 1;
        for(int kth_bits=0;kth_bits<bits;kth_bits++){
            num= num ^ (1<<kth_bits);// Toggle  kth_bits
        }
        return num;
    }
};

class Solution {
public:
    int findComplement(int num) {
        int ans=0;
        int required=floor(log2(num))+1;
        for(int bit=0;bit<required;bit++){
            int set_bit=num&(1<<bit);
            if(set_bit==0)ans+=1*(1<<bit);
            else ans+=0*(1<<bit);
        }
        return ans;
    }
};


class Solution {
public:
    int findComplement(int num) {
        int bits=floor(log2(num)) + 1;
        unsigned long long mask=(1LL<<bits) - 1;// when we need numbers of setbit of bits size 
        //int mask=pow(2,bits) - 1;
        return mask ^ num;
    }
};
// However INT_MAX = 2147483647, so this value cannot be represented in signed int, which causes:
// signed integer overflow
// That is exactly the error message:
// runtime error: signed integer overflow


class Solution {
public:
    int findComplement(int num) {
        int mask = 0;
        while(mask < num){
            mask = (mask << 1) | 1;
        }
        return mask ^ num;
    }
};
// However INT_MAX = 2147483647, so this value cannot be represented in signed int, which causes:
// signed integer overflow
// That is exactly the error message:
// runtime error: signed integer overflow
