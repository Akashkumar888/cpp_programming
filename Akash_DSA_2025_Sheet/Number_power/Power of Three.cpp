
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0)return false;
        double num=log10(n)/log10(3);
        return num==int(num);
    }
};


class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0)return false;
        int assume=pow(3,19); // it is range in 32 bit int
        int rem=assume%n;
        return rem==0;
    }
};


