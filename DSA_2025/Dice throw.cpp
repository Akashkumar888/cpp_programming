
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


class Solution {
public:
int MOD=1e9+7;
int solve(int n,int k,int sum,vector<vector<int>>&dp){
      if(n==0 && sum==0)return 1;
      if(n==0 || sum<0)return 0;
      if(dp[n][sum]!=-1)return dp[n][sum];
      int cnt=0;
      for(int i=1;i<=k;i++){
          cnt=(cnt%MOD+solve(n-1,k,sum-i,dp)%MOD)%MOD;
      }
      return dp[n][sum]=cnt;
  }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        return solve(n,k,target,dp);
    }
};
