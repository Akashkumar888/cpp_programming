
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
    bool isBitSet(int n) {
        // code here
        if(n==0)return false;
        int bits=totalBits(n);
        for(int bit=0;bit<bits;bit++){
            int kth_bit=(1<<bit)&n;
            if(kth_bit==0)return false;
        }
        return true;
    }
};


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
    bool isBitSet(int n) {
        // code here
        if(n==0)return false;
        int bits=totalBits(n);
        int setBits=__builtin_popcount(n);
        if(setBits!=bits)return false;
        return true;
    }
};

class Solution {
  public:
    bool isBitSet(int n) {
        // code here
        if(n==0)return false;
        while(n>0){
            int kth_bit=(n&1);
            if(kth_bit==0)return false;
            n=n>>1;
        }
        return true;
    }
};


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
    bool isBitSet(int n) {
        // code here
        if(n==0)return false;
        int bits=totalBits(n);
        int masks=(1<<bits)-1;
        int XOR=n^masks;
        if(XOR!=0)return false;
        return true;
    }
};


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
    bool isBitSet(int n) {
        // code here
        if(n==0)return false;
        int bits=totalBits(n);
        int masks=(1<<bits)-1;
        if(masks==n)return true;
        return false;
    }
};


class Solution {
  public:
    bool isBitSet(int n) {
        // code here
        if(n==0) return false;
        return (n & (n+1))==0;
    }
};

class Solution {
  public:
    bool isBitSet(int n) {
        // code here
        return n>0 && ((n&(n+1))==0);
    }
};

class Solution {
  public:
    bool isBitSet(int n) {
        // code here
        if(n==0) return false;

        int x=n+1;

        return (x&(x-1))==0;
    }
};


class Solution {
  public:
    bool isBitSet(int n) {
        // code here
        if(n==0) return false;

        int bits=log2(n)+1;

        int mask=(1<<bits)-1;

        return n==mask;
    }
};

class Solution {
  public:
    bool isBitSet(int n) {
        // code here
        if(n==0) return false;

        int x=n^(n>>1);

        return (x&(x-1))==0;
    }
};

class Solution {
  public:
    bool isBitSet(int n) {
        // code here
        if(n==0) return false;

        int x=n+1;

        return (x & -x)==x;
    }
};

