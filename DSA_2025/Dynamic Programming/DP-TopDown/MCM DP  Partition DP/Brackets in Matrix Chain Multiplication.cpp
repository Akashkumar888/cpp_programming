
class Solution {
  public:
  string helper(int i,int j,vector<vector<int>>&brackets){
      if(i==j){
          char ch='A'+(i-1);
          string temp="";
          temp+=ch;
          return temp;
      }
      int k = brackets[i][j];
    return "(" + helper(i,k,brackets) + helper(k+1,j,brackets) + ")";
  }
   int solve(int i,int j,vector<int>&arr,vector<vector<int>>&dp,vector<vector<int>>&brackets){
      if(i==j)return 0;
      if(dp[i][j]!=-1)return dp[i][j];
      int minCost=INT_MAX;
        for (int k=i;k<j;k++){
            int cost=arr[i-1]*arr[k]*arr[j]+solve(i,k,arr,dp,brackets)+solve(k+1,j,arr,dp,brackets);
            if (cost < minCost) {
                minCost = cost;
                brackets[i][j] = k;   // correct index
            }
        }
        return dp[i][j] = minCost;
  }
    string matrixChainOrder(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        vector<vector<int>>brackets(n,vector<int>(n,0));
        solve(1,n-1,arr,dp,brackets);
        return helper(1,n-1,brackets);
    }
};


class Solution {
  public:
  string helper(int i,int j,vector<vector<int>>&brackets){
      if(i==j){
          char ch='A'+(i-1);
          string temp="";
          temp+=ch;
          return temp;
      }
      int k = brackets[i][j];
    return "(" + helper(i,k,brackets) + helper(k+1,j,brackets) + ")";
  }
    string matrixChainOrder(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(n,INT_MAX));
        vector<vector<int>>brackets(n,vector<int>(n,0));
        for(int i=1;i<n;i++)dp[i][i]=0;
        for(int i=n-1;i>=1;i--){
            for(int j=i+1;j<n;j++){
                int minCost=INT_MAX;
                for (int k=i;k<j;k++){
                    int cost=arr[i-1]*arr[k]*arr[j]+ dp[i][k] + dp[k+1][j];
                    if (cost < minCost) {
                        minCost = cost;
                        brackets[i][j] = k;   // correct index
                    }
                }
                dp[i][j] = minCost;
            }
        }
        dp[1][n-1];
        return helper(1,n-1,brackets);
    }
};
