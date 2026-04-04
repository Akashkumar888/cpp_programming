class Solution {
  public:
// top-down code
  int solve(int n,vector<int>&dp){
    //   if(n==1)return 2;
    //   if(n==2)return 3;
      if(n<=2)return n+1;
      if(dp[n]!=-1)return dp[n];
      return dp[n]=solve(n-1,dp)+solve(n-2,dp);
  }
    int countStrings(int n) {
        // code here
        vector<int>dp(n+1,-1);
        return solve(n,dp);
    }
};

class Solution {
  public:
    int countStrings(int n) {
        // code here
        // bottom-up code
        vector<int>dp(n+1,0);
        dp[1]=2;
        dp[2]=3;
        for(int i=3;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};

class Solution {
  public:
    int countStrings(int n) {
        // code here
        // bottom-up space optimised code
        if(n<=2)return n+1;
        int a=2;
        int b=3;
        int sum=a+b;
        for(int i=3;i<=n;i++){
            sum=a+b;
            a=b;
            b=sum;
        }
        return sum;
    }
};
