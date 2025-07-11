// T(n) = number of binary strings of length n with at least one pair of consecutive 1's
// Total(n) = total number of binary strings of length n = 2^n
// Valid(n) = number of binary strings of length n with no consecutive 1's
// Then: T(n)=Total(n)−Valid(n)

// ✅ Step 1: Total binary strings = 2^n
// Because each position can be 0 or 1 → 2 choices → total = 2^n

// ✅ Step 2: Valid strings with no consecutive 1's
// This is a well-known problem. The count of such strings follows the Fibonacci sequence:
// Valid(n) = Fib(n+2)
// Where:

// Fib(0) = 0
// Fib(1) = 1
// Fib(2) = 1
// Fib(3) = 2
// Fib(4) = 3
// Fib(5) = 5
// Fib(6) = 8

// ✅ So the pattern is: T(n) = 2ⁿ - Fib(n+2)


class Solution {
  public:
  int fib(int n,vector<int>&dp){
      if(n==1 || n==2)return 1;
      if(dp[n]!=-1)return dp[n];
      return dp[n]=fib(n-1,dp)+fib(n-2,dp);
  }
    int countConsec(int n) {
        // code here
        // Increase the size of the DP array to accommodate fib(n + 2) safely:
        vector<int>dp(n+3,-1);// n+3 ensures safe access for fib(n+2)
        // Use 1 << n (or pow(2, n)) to compute 2ⁿ.
        // return (1<<n) - fib(n+2,dp);
        return pow(2,n) - fib(n+2,dp);
    }
};
// ⏱ Time Complexity: O(n)
// Because each fib(k) is computed once due to memoization.

// 🧠 Space Complexity: O(n)
// For the dp array (can be reduced with bottom-up).

class Solution {
  public:
  int fib(int n){
      int first=1,second=1;
      int sum=0;
      for(int i=3;i<=n;i++){
          sum=first+second;
          first=second;
          second=sum;
      }
      return sum;
  }
    int countConsec(int n) {
        // code here
        return (1<<n) - fib(n+2);
    }
};

// ⏱ Time Complexity: O(n)
// Iterates from 3 to n+2.

// 🧠 Space Complexity: O(1)
// Only three integer variables used (first, second, sum).

