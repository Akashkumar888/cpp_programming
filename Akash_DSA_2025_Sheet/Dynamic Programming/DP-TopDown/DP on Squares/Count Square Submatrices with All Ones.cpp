
class Solution {
public:
int f(int i,int j,vector<vector<int>>& matrix, vector<vector<int>>&dp){
    if(i<0 || j<0 || matrix[i][j]==0)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int right=f(i-1,j,matrix,dp);
    int dia=f(i-1,j-1,matrix,dp);
    int down=f(i,j-1,matrix,dp);
    return dp[i][j]= 1+ min({right,dia,down});
}
    int countSquares(vector<vector<int>>& matrix) {
      int m=matrix.size();
      int n=matrix[0].size();
      vector<vector<int>>dp(301,vector<int>(301,-1));
     int cnt=0;
     for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cnt+=f(i,j,matrix,dp);
        }
     } 
     return cnt;
    }
};


class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
      int m=matrix.size();
      int n=matrix[0].size();
      for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            if(matrix[i][j]==0)matrix[i][j]=0;
            else{
                matrix[i][j]=1+min(matrix[i-1][j-1],min(matrix[i-1][j],matrix[i][j-1]));
            }
        }
      }  
      int sum=0;
      for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            sum+=matrix[i][j];
        }
      }
      return sum;
    }
};
