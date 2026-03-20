
class Solution {
  public:// top down code
    int solve(int m, int n, int x,vector<vector<int>>&dp){
        if(x<0)return 0;
        if(n==0){
            if(x==0)return 1;
            return 0;
        }
        if(dp[n][x]!=-1)return dp[n][x];
        int ways=0;
        for(int value = 1; value <= m; value++){
            if(x-value>=0)ways+=solve(m,n-1,x-value,dp);
        }
        return dp[n][x]=ways;
    }
    int noOfWays(int m, int n, int x) {
        vector<vector<int>>dp(n+1,vector<int>(x+1,-1));// bottom up code
        return solve(m,n,x,dp);
    }
};

class Solution {
  public:// top down code
    int solve(int m, int n, int x,vector<vector<int>>&dp){
        if(x<0)return 0;
        if(n==0){
            if(x==0)return 1;
            return 0;
        }
        if(dp[n][x]!=-1)return dp[n][x];
        int ways=0;
        for(int value = 1; value <= m; value++){
            ways+=solve(m,n-1,x-value,dp);
        }
        return dp[n][x]=ways;
    }
    int noOfWays(int m, int n, int x) {
        vector<vector<int>>dp(n+1,vector<int>(x+1,0));// bottom up code
        dp[0][0]=1;
        for(int i=1;i<=n;i++){           // number of dice
            for(int sum=1;sum<=x;sum++){ // target sum
                int ways=0;
                for(int value=1;value<=m;value++){ // face value
                    if(sum-value>=0)ways+=dp[i-1][sum-value];
                }
                dp[i][sum]=ways;
            }
        }
        return dp[n][x];
    }
};


class Solution {
  public:
  int solve(int m,int n,int sum,vector<vector<int>>&dp){
      if(n==0 && sum==0)return 1;
      if(n==0 || sum<0)return 0;
      if(dp[n][sum]!=-1)return dp[n][sum];
      int cnt=0;
      for(int i=1;i<=m;i++){
          cnt+=solve(m,n-1,sum-i,dp);
      }
      return dp[n][sum]=cnt;
  }
    int noOfWays(int m, int n, int x) {
        // code here
        vector<vector<int>>dp(n+1,vector<int>(x+1,-1));
        return solve(m,n,x,dp);
    }
};

