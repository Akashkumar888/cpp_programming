

class Solution {
public:
int solve(int i,int j,vector<vector<int>>&mat,vector<vector<int>>&dp){
      if(i<0||j<0 || i>=mat.size() || j>=mat[i].size())return INT_MAX;
      if(i==0)return mat[0][j];
      if(dp[i][j]!=-1)return dp[i][j];
      int diaLeft=solve(i-1,j+1,mat,dp);
      int up=solve(i-1,j,mat,dp);
      int dia=solve(i-1,j-1,mat,dp);
      if(diaLeft==INT_MAX && up==INT_MAX && dia==INT_MAX)return dp[i][j]=INT_MAX;
      int minPathSum=min({diaLeft,up,dia})+mat[i][j];
      return dp[i][j]=minPathSum;
  }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>>dp(m,vector<int>(n+1,-1));
        int minSum=INT_MAX;
        for(int j=0;j<n;j++){
            minSum=min(minSum,solve(m-1,j,matrix,dp));
        }
        return minSum;
    }
};