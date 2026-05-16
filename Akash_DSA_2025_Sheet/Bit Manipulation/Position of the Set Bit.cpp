
class Solution {
  public:
  int totalBits(int n){
      int count=0;
      while(n>0){
          n=n/2;
          count++;
      }
      return count;
  }
    int findPosition(int n) {
        // code here
        int total=totalBits(n);
        int count=0;
        while(n>0){
            n=(n&(n-1));
            count++;
            if(count>1)return -1;
        }
        return total;
    }
};



class Solution {
  public:
    int findPosition(int n) {
        // code here
        int num=n;
        int totalBits=0;
        int setBits=0;
        while(n>0){
            if(num>0){
            setBits++;
            num=(num&(num-1));
            }
            totalBits++;
            n=n/2;
        }
        return setBits>1?-1:totalBits;
    }
};


class Solution {
  public:
    int findPosition(int n) {
        // code here
        int num=n;
        int totalBits=0;
        int setBits=__builtin_popcount(n);
        while(n>0){
            totalBits++;
            n=n/2;
        }
        return setBits>1?-1:totalBits;
    }
};


class Solution {
  public:
    int findPosition(int n) {
        // code here
        int num=n;
        int totalBits=0;
        int setBits=__builtin_popcount(n);
        while(n>0){
            totalBits++;
            n=n>>1;
        }
        return setBits>1?-1:totalBits;
    }
};

class Solution {
  public:
    int findPosition(int n) {
        // code here
        double x=log(n)/log(2);
        int value=int(x);
        if(x==value)return value+1;
        return -1;
    }
};


class Solution {
  public:
    int findPosition(int n) {
        // code here
        int totalBits=0;
        while(n>1){
            totalBits++;
            if(n&1)return -1;
            n=n/2;
        }
        return totalBits+1;
    }
};



class Solution {
  public:
    int findPosition(int n) {
        if(n == 0 || (n & (n - 1)) != 0) return -1;
        
        int pos = 1;
        while(n > 1){
            n >>= 1;
            pos++;
        }
        return pos;
    }
};



class Solution {
  public:
    int findPosition(int n) {
        if(n == 0 || (n & (n - 1)) != 0) return -1;
        return __builtin_ctz(n) + 1;
    }
};



class Solution {
  public:
    int findPosition(int n) {
        if(n == 0 || (n & (n - 1)) != 0) return -1;
        return log2(n) + 1;
    }
};



class Solution {
  public:
    int findPosition(int n) {
        if(n == 0 || (n & (n - 1)) != 0) return -1;

        int pos = 1;
        while(!(n & 1)){
            n >>= 1;
            pos++;
        }
        return pos;
    }
};