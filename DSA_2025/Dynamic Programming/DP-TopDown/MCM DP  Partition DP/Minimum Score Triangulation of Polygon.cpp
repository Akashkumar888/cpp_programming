
class Solution {
public:
int solve(int i,int j,vector<int>&values,vector<vector<int>>&dp){
      if(i==j)return 0;
      if(dp[i][j]!=-1)return dp[i][j];
      int leastNumber=INT_MAX;
      for(int k=i;k<=j-1;k++){
         int step=(values[i-1]*values[k]*values[j])+solve(i,k,values,dp)+solve(k+1,j,values,dp);
         leastNumber=min(leastNumber,step);
      }
    return dp[i][j]=leastNumber;  
  }
    int minScoreTriangulation(vector<int>& values) {
        int n=values.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(1,n-1,values,dp);
    }
};

class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int n=values.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int i=0;i<n;i++)dp[i][i]=0;
        for(int i=n-1;i>=1;i--){
            for(int j=i+1;j<n;j++){
                int leastNumber=INT_MAX;
                for(int k=i;k<=j-1;k++){
                    int step=(values[i-1]*values[k]*values[j])+dp[i][k]+dp[k+1][j];
                    leastNumber=min(leastNumber,step);
                }
                dp[i][j]=leastNumber; 
            }
        }
        return dp[1][n-1];
    }
};

class Solution {
public:
    int solve(int i, int j, vector<int>& values, vector<vector<int>>& dp) {
        // base case: no triangle possible
        if (j - i < 1) return 0;

        // memoized result
        if (dp[i][j] != -1) return dp[i][j];

        int ans = INT_MAX;

        // try every possible k
        for (int k = i; k < j; k++) {
            int cost = values[i - 1] * values[k] * values[j]
                     + solve(i, k, values, dp)
                     + solve(k + 1, j, values, dp);

            ans = min(ans, cost);
        }

        return dp[i][j] = ans;
    }

    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(1, n - 1, values, dp);
    }
};



class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i=n-1;i>=1;i--){
            for(int j=1;j<n;j++){
                if(j-i<1)continue;
                int ans = INT_MAX;
                // try every possible k
                for (int k = i; k < j; k++) {
                    int cost = values[i - 1] * values[k] * values[j]
                            + dp[i][k]
                            + dp[k+1][j];

                    ans = min(ans, cost);
                }
                dp[i][j] = ans;
            }
        }
        return dp[1][n-1];
    }
};


