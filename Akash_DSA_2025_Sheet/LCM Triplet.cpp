
class Solution {
  public:
    int lcmTriplets(int n) {
        // code here
        if (n<=2)return n;
        if (n==3)return 6;

        int res = 0;
        if(n%2!=0){
            // n is odd ⇒ use (n, n-1, n-2)
            res=n*(n-1)*(n-2);
        } 
        else{
            // n is even ⇒ two options:
            // Option 1: (n, n-1, n-3)
            // Option 2: (n-1, n-2, n-3) if n%3==0 (special case)
            if(n%3!=0){
                res=n*(n-1)*(n-3);
            } 
            else{
                res=(n-1)*(n-2)*(n-3);
            }
        }
        return res;
    }
};

// time complexity: o(1)
// space complexity: o(1)

class Solution {
  public:
    int lcmOfTwoNumber(int a,int b) {
        return (a*b)/(__gcd(a, b));
    }
    int lcm(int a, int b,int c) {
        return lcmOfTwoNumber(a,lcmOfTwoNumber(b,c));
    }
    int lcmTriplets(int n) {
        // code here
        if (n<=2)return n;
        if (n==3)return 6;
        int res = 0;
        // Try 3 best candidates (handle all even/odd/special cases)
        res = max({lcm(n,n-1,n-2),lcm(n,n-1,n-3),lcm(n-1,n-2,n-3)});
        return res;
    }
};

