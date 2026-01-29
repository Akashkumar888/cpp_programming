

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


class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>>dp(m,vector<int>(n,INT_MAX));
        // base case 
        for(int j=0;j<n;j++)dp[0][j]=matrix[0][j];
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                int diaLeft=INT_MAX,up=INT_MAX,dia=INT_MAX;
                      if(i-1>=0 && j+1<n) diaLeft=dp[i-1][j+1];
                      if(i-1>=0) up=dp[i-1][j];
                      if(i-1>=0 && j-1>=0) dia=dp[i-1][j-1];
                      if(diaLeft==INT_MAX && up==INT_MAX && dia==INT_MAX)return dp[i][j]=INT_MAX;
                      int minPathSum=min({diaLeft,up,dia})+matrix[i][j];
                      dp[i][j]=minPathSum;
            }
        }
        int minSum=INT_MAX;
        for(int j=0;j<n;j++){
            minSum=min(minSum,dp[m-1][j]);
        }
        return minSum;
    }
};

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int>prev(n,INT_MAX),temp(n,INT_MAX);
        // base case 
        for(int j=0;j<n;j++)prev[j]=matrix[0][j]; // base start from first prev then curr or temp
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                int diaLeft=INT_MAX,up=INT_MAX,dia=INT_MAX;
                      if(i-1>=0 && j+1<n) diaLeft=prev[j+1];
                      if(i-1>=0) up=prev[j];
                      if(i-1>=0 && j-1>=0) dia=prev[j-1];
                      if(diaLeft==INT_MAX && up==INT_MAX && dia==INT_MAX)return temp[j]=INT_MAX;
                      int minPathSum=min({diaLeft,up,dia})+matrix[i][j];
                      temp[j]=minPathSum;
            }
            prev=temp;
        }
        int minSum=INT_MAX;
        for(int j=0;j<n;j++){
            minSum=min(minSum,prev[j]); // here only use prev not use temp 
        }
        return minSum;
    }
};