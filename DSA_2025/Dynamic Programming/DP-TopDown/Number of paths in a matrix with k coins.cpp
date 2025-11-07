
class Solution {
  public:
  int dx[2]={1,0};
  int dy[2]={0,1};
  int solve(int i,int j,int n,int m,int &sum,int k,vector<vector<int>>&mat,vector<vector<vector<int>>>&dp){
      if(i<0 || j<0 || i>=n || j>=m ||mat[i][j]==-1)return 0;
      // prune before indexing dp
      if (sum > k) return 0;
        
      if(i==n-1 && j==m-1){
          if(sum==k)return 1;
          return 0;
      }
        
      if(dp[i][j][sum]!=-1)return dp[i][j][sum];
      int ways=0;
      int temp=mat[i][j];
      mat[i][j]=-1;
      for(int l=0;l<2;l++){
          int new_i=i+dx[l];
          int new_j=j+dy[l];
          // these below case beacause here i access matrix element 
          // But you NEVER check:
          // whether (new_i, new_j) is inside bounds
          // whether mat[new_i][new_j] is 0 (visited)
          // So you may do mat[-1][0] → runtime error / wrong answer.
          // ✅ Fix
          // Add checks before using mat[new_i][new_j]:
          if(new_i < 0 || new_j < 0 || new_i >= n || new_j >= m) continue;
          if(mat[new_i][new_j] == -1) continue;
          sum+=mat[new_i][new_j];
          ways+=solve(new_i,new_j,n,m,sum,k,mat,dp);
          sum-=mat[new_i][new_j];
      }
      mat[i][j]=temp;
      return dp[i][j][sum]=ways;
  }
    int numberOfPath(vector<vector<int>>& mat, int k) {
        // Code Here
        int n=mat.size();
        int m=mat[0].size();
        int sum = mat[0][0];   // FIXED
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(k+1,-1)));
        // You NEVER add the starting cell value (0,0) to sum
        return solve(0,0,n,m,sum,k,mat,dp);
    }
};



class Solution {
public:
    int dx[2] = {1, 0};
    int dy[2] = {0, 1};
    int n, m;

    int dfs(int i, int j, int rem,
            vector<vector<int>>& mat,
            vector<vector<vector<int>>>& dp) {

        if (i < 0 || j < 0 || i >= n || j >= m) return 0;

        // consume current cell
        rem -= mat[i][j];
        if (rem < 0) return 0;

        // destination: must exactly match remaining sum
        if (i == n - 1 && j == m - 1) return rem == 0;

        int &memo = dp[i][j][rem];
        if (memo != -1) return memo;

        int ways = 0;
        // move down or right
        ways += dfs(i + 1, j, rem, mat, dp);
        ways += dfs(i, j + 1, rem, mat, dp);

        return memo = ways;
    }

    int numberOfPath(vector<vector<int>>& mat, int k) {
        n = mat.size();
        m = mat[0].size();
        if (k < 0) return 0;
        // dp[i][j][rem]: ways from (i,j) to end with remaining sum = rem
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k + 1, -1)));
        return dfs(0, 0, k, mat, dp);
    }
};
