// User function Template for C++

class Solution {
  public:
    int rotationCount(long long R, long long D) {
        // code here
        int sumOfDigits=0;
        while(D>0 || R>0){
            int r1=R%10;
            int r2=D%10;
            int diff = abs(r1 - r2);
            sumOfDigits += min(diff, 10 - diff);
            D/=10;
            R/=10;
        }
        return sumOfDigits;
    }
};
