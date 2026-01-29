
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

