
class Solution {
  public:
// Given a floor of dimensions 2 x n and tiles of dimensions 2 x 1, 
// the task is to find the number of ways the floor can be tiled.
// A tile can either be placed horizontally i.e as a 1 x 2 tile or vertically i.e as 2 x 1 tile. 
// Note: Two tiling arrangements are considered different if the placement of at least one tile differs.
  // 1 1 2 3 5 8 13 
  int solve(int n,vector<int>&dp){
      if(n<=2)return n;
      if(dp[n]!=-1)return dp[n];
      return dp[n]=solve(n-1,dp)+solve(n-2,dp);
  }
    int numberOfWays(int n) {
        // code here
        vector<int>dp(n+1,-1);
        return solve(n,dp);
    }
};

class Solution {
  public:
// Given a floor of dimensions 2 x n and tiles of dimensions 2 x 1, 
// the task is to find the number of ways the floor can be tiled.
// A tile can either be placed horizontally i.e as a 1 x 2 tile or vertically i.e as 2 x 1 tile. 
// Note: Two tiling arrangements are considered different if the placement of at least one tile differs.
  // 1 1 2 3 5 8 13 
    int numberOfWays(int n) {
        // code here
        vector<int>dp(n+1,0);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};

class Solution {
  public:
// Given a floor of dimensions 2 x n and tiles of dimensions 2 x 1, 
// the task is to find the number of ways the floor can be tiled.
// A tile can either be placed horizontally i.e as a 1 x 2 tile or vertically i.e as 2 x 1 tile. 
// Note: Two tiling arrangements are considered different if the placement of at least one tile differs.
  // 1 1 2 3 5 8 13 
    int numberOfWays(int n) {
        // code here
        int prev2=1;
        int prev1=1;
        for(int i=2;i<=n;i++){
            int curr=prev2+prev1;
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
};