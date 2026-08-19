
class Solution {
  public:
  int solve(int n,vector<int>&dp){
      if(n<=1)return 1;
      if(n==2)return 2;
      if(dp[n]!=-1)return dp[n];
      return dp[n]=solve(n-1,dp)+(n-1)*solve(n-2,dp);
  }
    int countFriendsPairings(int n) {
        // code here
        vector<int>dp(n+1,-1);
        return solve(n,dp);
    }
};


class Solution {
  public:
    int countFriendsPairings(int n) {
        // code here
        vector<int>dp(n+1,0);
        dp[0]=1;
        dp[1]=1;
        dp[2]=2;
        for(int i=3;i<=n;i++){
            dp[i]=dp[i-1] +(i-1)*dp[i-2];
        }
        return dp[n] ;
    }
};


class Solution {
  public:
    int countFriendsPairings(int n) {
        if(n <= 1)return 1;
        if(n == 2)return 2;

        int prev2 = 1; // f(1)
        int prev1 = 2; // f(2)

        for(int i = 3; i <= n; i++) {
            int curr = prev1 + (i - 1) * prev2;

            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};

