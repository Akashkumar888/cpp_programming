
class Solution {
  public:
  int solve(int i,int n,vector<int>&coins,int sum,vector<vector<int>>&dp){
        if(i==n-1){
          if(sum%coins[i]==0)return sum/coins[i];
          else return 1e9;
        }
        if(dp[i][sum]!=-1)return dp[i][sum];
        int pick=INT_MAX;
        if(coins[i]<=sum)pick=1+solve(i,n,coins,sum-coins[i],dp);
        int notpick=solve(i+1,n,coins,sum,dp);
        return dp[i][sum]=min(pick,notpick);
    }
      int coinChange(vector<int>& coins, int amount) {
          int n=coins.size();
          vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
          int mincoins=solve(0,n,coins,amount,dp);
          if(mincoins==1e9)return -1;
          return mincoins;
      }
  };
  
  