// AAA
// Ctrl+A
// Ctrl+C
// Ctrl+V
// Ctrl+V

// answer n = 9

class Solution {
  public:
  int solve(int n,vector<int>&dp){
      if(n<=6)return n;
      if(dp[n]!=-1)return dp[n];
      int maxNumber=0;
      for(int j=1;j<=n-3;j++){
          maxNumber=max(maxNumber,solve(j,dp)*(n-j-1));
      }
      return dp[n] = maxNumber;
  }
    int optimalKeys(int n) {
        // code here
        vector<int>dp(n+1,0);
        for(int i=1;i<=6;i++)dp[i]=i;
        for(int i=1;i<=n;i++){
            int maxNumber=0;
              for(int j=1;j<=n-3;j++){
                  maxNumber=max(maxNumber,solve(j,dp)*(n-j-1));
              }
            dp[n] = maxNumber;
        }
        return dp[n];
    }
};

class Solution {
  public:
    int optimalKeys(int n) {
        vector<int> dp(n + 1, 0);
        // base cases
        for(int i = 1; i <= min(n, 6); i++){
            dp[i] = i;
        }
        // build dp
        for(int i = 7; i <= n; i++){
            int maxNumber = 0;
            for(int j = 1; j <= i - 3; j++){
                /*
                    dp[j] already formed

                    Then:
                    Ctrl+A
                    Ctrl+C
                    remaining pastes
                */

                int current = dp[j] * (i - j - 1);
                maxNumber = max(maxNumber, current);
            }
            dp[i] = maxNumber;
        }
        return dp[n];
    }
};
