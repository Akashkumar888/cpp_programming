

class Solution {
  public:
  int solve(int i,int j,vector<int>&arr,vector<vector<int>>&dp){
      if(i==j)return 0;
      if(dp[i][j]!=-1)return dp[i][j];
      int leastNumber=INT_MAX;
      for(int k=i;k<=j-1;k++){
         int step=(arr[i-1]*arr[k]*arr[j])+solve(i,k,arr,dp)+solve(k+1,j,arr,dp);
         leastNumber=min(leastNumber,step);
      }
    return dp[i][j]=leastNumber;  
  }
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(1,n-1,arr,dp);
    }
};


class Solution {
  public:
  int solve(int i,int j,vector<int>&arr,vector<vector<int>>&dp){
      if(i==j)return 0;
      if(dp[i][j]!=-1)return dp[i][j];
      int leastNumber=INT_MAX;
      for(int k=i;k<j;k++){
         int step=(arr[i-1]*arr[k]*arr[j])+solve(i,k,arr,dp)+solve(k+1,j,arr,dp);
         leastNumber=min(leastNumber,step);
      }
    return dp[i][j]=leastNumber;  
  }
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return solve(1,n-1,arr,dp);
    }
};


class Solution {
  public:
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(n,INT_MAX));
        for(int i=1;i<n;i++)dp[i][i]=0;
        for(int i=n-1;i>=1;i--){
            for(int j=i+1;j<n;j++){
                int leastNumber=INT_MAX;
              for(int k=i;k<j;k++){
                 int step=(arr[i-1]*arr[k]*arr[j])+dp[i][k]+dp[k+1][j];
                 leastNumber=min(leastNumber,step);
              }
                 dp[i][j]=leastNumber; 
            }
        }
        return dp[1][n-1];
    }
};