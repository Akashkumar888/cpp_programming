
class Solution {
public:
    int fib(int n) {
        if(n==0 || n==1){
            return n;
        }
        return fib(n-1)+fib(n-2);
    }
};

class Solution {
public:
    int fib(int n) {
        if(n<=1)return n;
        return fib(n-1)+fib(n-2);
    }
};

class Solution {
public:
    int fib(int n) {
      if(n<=1) return n;
      vector<int>dp(n+1,-1);
      dp[0]=0;
      dp[1]=1;
      for(int i=2;i<=n;i++){
          dp[i]=dp[i-1]+dp[i-2];
      }
      return dp[n];
    }
};

class Solution {
public:
int t[31];
int solve(int n){
    if(n==0||n==1) return n;
    if(t[n]!=-1)return t[n];
    return fib(n-1)+fib(n-2); 
}
    int fib(int n) {
       memset(t,-1,sizeof(t));
       return solve(n);
    }
};

// memset is a C/C++ function used to set all bytes of a memory block to a specific value.
// ✅ What this does
// t is an array int t[31];
// memset(t, -1, sizeof(t)); fills every byte of the array t with -1
// This initializes the dp array with -1, meaning value not computed yet (for memoization).
// ✅ Why -1?
// Because Fibonacci values are never -1, so -1 means "not calculated yet".
// ✅ Breakdown of memset
// Example — ✅ correct:

// memset(arr, 0, sizeof(arr)); // sets all to 0 properly
// memset(arr, -1, sizeof(arr)); // sets all to -1 properly
// Example — ❌ wrong:
// memset(arr, 5, sizeof(arr)); // NOT safe for integers!
// ✅ Equivalent modern way (safer in C++)

//fill(t.begin(),t.end(),-1);
// Instead of memset:
// fill(begin(t), end(t), -1);
// both lines do the same job, but they work in different situations.

// ✅ Your commented line
// // fill(t.begin(), t.end(), -1);
// This works only if t is a vector, because vectors have .begin() and .end().
// Example where this is valid:
// vector<int> t(31);
// fill(t.begin(), t.end(), -1);

// ✅ The used line
// fill(begin(t), end(t), -1);
// This works for both arrays and vectors, because begin() and end() are global template functions in <iterator>.
// Example:
// int t[31];
// fill(begin(t), end(t), -1);

// For all algorithms in <algorithm> that take iterators, you can use either:

//  For vectors	                               For arrays	                                            Universal modern style
//  t.begin(), t.end()	                        t, t+n	                                                begin(t), end(t) ✅

// So yes, this pattern works for:
// reverse(begin(t), end(t));
// sort(begin(t), end(t));
// max_element(begin(t), end(t));
// min_element(begin(t), end(t));
// accumulate(begin(t), end(t), 0);

// Works for vector, array, string — any container supporting iterators.

class Solution {
public:
int solve(int n,vector<int>&dp){
    if(n<=1)return n;
    if(dp[n]!=-1)return dp[n];
    return dp[n]=solve(n-1,dp) +solve(n-2,dp);
}
    int fib(int n) {
       vector<int>dp(n+1,-1);
        return solve(n,dp);
    }
};


class Solution {
public:
    int fib(int n) {
      if(n<=1)return n;
        vector<int>dp(n+1);
        dp[0]=0;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};
class Solution {
  public:
  int fib(int n) {
  if(n<=1) return n;
  int a=0,b=1;
  int sum=0;
  for(int i=1;i<n;i++){
      sum=a+b;
      a=b;
      b=sum;
    }
    return sum;
    }
};

class Solution {
  public:
  int fib(int n) {
  if(n<=1) return n;
  int prev2=0,prev1=1;
  int curr=0;
  for(int i=2;i<=n;i++){
      curr=prev1+prev2;
      prev2=prev1;
      prev1=curr;
    }
    return curr;
    }
};


class Solution {
  public:
  int fib(int n) {
  if(n<=1) return n;
  int prev2=0,prev1=1;
  int curr=0;
  for(int i=2;i<=n;i++){
      curr=prev1+prev2;
      prev2=prev1;
      prev1=curr;
    }
    return prev1;
    }
};
