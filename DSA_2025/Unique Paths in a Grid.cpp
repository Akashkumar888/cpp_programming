
class Solution {
  public:
  vector<vector<int>>directions={{0,1},{1,0}};
  int solve(int i,int j,int n,int m,vector<vector<int>>&grid,vector<vector<int>>&dp){
      if(i<0 || i>=n ||j<0 ||j>=m||grid[i][j]==1)return 0;
      if(i==n-1 && j==m-1)return 1;
      if(dp[i][j]!=-1)return dp[i][j];
      grid[i][j]=1;
      int ways=0;
      for(auto &dir:directions){
          int new_i=i+dir[0];
          int new_j=j+dir[1];
          ways+=solve(new_i,new_j,n,m,grid,dp);
      }
      grid[i][j]=0;
      dp[i][j]=ways;
      return ways;
  }
    int uniquePaths(vector<vector<int>> &grid) {
        // code here
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(0,0,n,m,grid,dp);
    }
};

