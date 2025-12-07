
// User function Template for C++

class Solution {
  public:
  int solve(int i,int j,vector<vector<int>>&mat,vector<vector<int>>&dp){
      if(i<0||j<0 || i>=mat.size() || j>=mat[i].size())return INT_MIN;
      if (i==0)return mat[0][j];
      if(dp[i][j]!=-1)return dp[i][j];
      int diaLeft=solve(i-1,j+1,mat,dp);
      int up=solve(i-1,j,mat,dp);
      int dia=solve(i-1,j-1,mat,dp);
      if(diaLeft==INT_MIN && up==INT_MIN && dia==INT_MIN)return dp[i][j]=INT_MIN;
      int maxPathSum=max({diaLeft,up,dia})+mat[i][j];
      return dp[i][j]=maxPathSum;
  }
    int maximumPath(vector<vector<int>>& mat) {
        // code here
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>>dp(m,vector<int>(n+1,-1));
        int maxSum=INT_MIN;
        for(int j=0;j<n;j++){
            maxSum=max(maxSum,solve(m-1,j,mat,dp));
        }
        return maxSum;
    }
};