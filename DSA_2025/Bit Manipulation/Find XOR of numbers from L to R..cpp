
// User function Template for C++

class Solution {
  public:
  int solve(int n){
      if(n%4==1)return 1;
      else if(n%4==2)return n+1;
      else if(n%4==3)return 0;
      else if(n%4==0)return n;
  }
    int findXOR(int l, int r) {
        // complete the function here
        return solve(l-1) ^ solve(r);
    }
};