
class Solution {
  public:
  int solve(int i,int j,int m,int n,vector<vector<int>>&mat,vector<vector<int>>&dp){
      if(i>=m || j==n||i<0)return 0;
      if(dp[i][j]!=-1)return dp[i][j];
      int sum=0;
      sum=max(sum,mat[i][j]+solve(i,j+1,m,n,mat,dp));
      sum=max(sum,mat[i][j]+solve(i-1,j+1,m,n,mat,dp));
      sum=max(sum,mat[i][j]+solve(i+1,j+1,m,n,mat,dp));
      return dp[i][j]=sum;
  }
    int maxGold(vector<vector<int>>& mat) {
        // code here
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        int maxSum=0;
        for(int i=0;i<m;i++){
            maxSum=max(maxSum,solve(i,0,m,n,mat,dp));
        }
        return maxSum;
    }
};



// ✅ Time Complexity
// You are solving the problem using Top-Down Dynamic Programming (Memoization).
// The recursive function solve(i, j, ...) is called for each cell only once due to memoization.
// There are m rows and n columns, so the total number of unique states is:
// Time Complexity=O(m×n)
// Each cell does constant work (checking 3 directions), and the result is cached in dp.

// ✅ Space Complexity
// You are using two main sources of space:
// DP Table dp[m+1][n+1]:
// Stores results of subproblems.
// Space: O(m × n)
// Call Stack (Recursion):
// The maximum depth of recursion is O(n) (since j increases with each call).
// Space: O(n)
// So total space is:
// Space Complexity=O(m×n)+O(n)=O(m×n)
// 🔹 The O(n) call stack is negligible compared to O(m × n) for large m and n.


class Solution {
  public:
    int maxGold(vector<vector<int>>& mat) {
        // code here
        int m=mat.size();
        int n=mat[0].size();
        for(int col=n-2;col>=0;col--){
            for(int row=0;row<m;row++){
                int best=mat[row][col+1]; // right
                if(row>0)best=max(best,mat[row-1][col+1]);// right up
                if(row+1<m)best=max(best,mat[row+1][col+1]);// right down
                mat[row][col]+=best;
            }
        }
        int maxSum=0;
        for(int i=0;i<m;i++){
            maxSum=max(maxSum,mat[i][0]);
        }
        return maxSum;
    }
};

// ⏱ Time Complexity: O(m × n)
// You iterate over each column from right to left: n - 1 columns ⇒ O(n)
// For each column, you iterate over all rows: m rows ⇒ O(m)
// Inside the nested loop, each operation is O(1)
// ✅ So, total time = O(m × n)

// 🧠 Space Complexity: O(1)
// You're updating the original mat in-place.
// No additional data structures like dp[][] are used.
// ✅ Hence, space = constant, i.e., O(1)
// Note: If modifying the original matrix wasn't allowed, you'd need a dp[m][n], which would make space complexity O(m × n).

