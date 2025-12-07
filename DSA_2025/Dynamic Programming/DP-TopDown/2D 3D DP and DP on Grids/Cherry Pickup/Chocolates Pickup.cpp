


class Solution {
  public:
//   c2 = r1 + c1 – r2 is valid only when both robots start at (0,0) and both robots always move down or right.
//   Two robots are collecting chocolates from this grid:
// Robot 1 starts at the top-left corner (0, 0)
// Robot 2 starts at the top-right corner (0, m - 1)
// Your task is to determine the maximum total number of chocolates both robots can collect while following these rules:
// From a cell (i, j), robots can move to cell (i + 1, j - 1), (i + 1, j), or (i + 1, j + 1).
// When a robot visits a cell, it collects all the chocolates there.
// If both robots land on the same cell, the chocolates in that cell are collected only once.
// Robots cannot move outside the boundaries of the grid.
// Both robots must continue moving until they reach the bottom row of the grid.
  int dx[3]={1,1,1};
  int dy[3]={-1,0,1};//From a cell (i, j), robots can move to cell (i + 1, j - 1), (i + 1, j), or (i + 1, j + 1).
  int solve(int r1,int c1,int c2,int n,int m,vector<vector<int>>&mat,vector<vector<vector<int>>>&dp){
      
      // r1 == r2 always
      int r2 = r1;  
      // out of bounds
      if(r1 < 0 || c1 < 0 || r2 < 0 || c2 < 0 || r1 >= n || c1 >= m || r2 >= n || c2 >= m)return INT_MIN;
      
      // Both robots must continue moving until they reach the bottom row of the grid.
        // last row
          if(r1 == n-1){
              if(c1 == c2) return dp[r1][c1][c2] = mat[r1][c1];
              return dp[r1][c1][c2] = mat[r1][c1] + mat[r1][c2];
          }
      
        if(dp[r1][c1][c2]!=-1)return dp[r1][c1][c2];
        
        int sum=INT_MIN;// because max cell value need 
        
      // chocolates collected
        int add = 0;
        if (r1 == r2 && c1 == c2) add = mat[r1][c1];// same cell → count once
        else add = mat[r1][c1] + mat[r2][c2];
        
        for(int k1 = 0; k1 < 3; k1++){
          int ni = r1 + dx[k1];
          int nj1 = c1 + dy[k1];

          for(int k2 = 0; k2 < 3; k2++){
              int nj2 = c2 + dy[k2];
              sum = max(sum, solve(ni, nj1, nj2, n, m, mat, dp));
          }
      } 
        
        if (sum == INT_MIN) return dp[r1][c1][r2] = INT_MIN;

      return dp[r1][c1][c2]=sum+add;
  }
    int maxChocolate(vector<vector<int>>& grid) {
        // code here
         // robot1 starts at (0,0)
         // robot2 starts at (0,m-1)
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m+1,-1)));
        int ans=solve(0,0,m-1,n,m,grid,dp);
        return ans==INT_MIN ? 0: ans;
    }
};


class Solution {
  public:
//   c2 = r1 + c1 – r2 is valid only when both robots start at (0,0) and both robots always move down or right.
//   Two robots are collecting chocolates from this grid:
// Robot 1 starts at the top-left corner (0, 0)
// Robot 2 starts at the top-right corner (0, m - 1)
// Your task is to determine the maximum total number of chocolates both robots can collect while following these rules:
// From a cell (i, j), robots can move to cell (i + 1, j - 1), (i + 1, j), or (i + 1, j + 1).
// When a robot visits a cell, it collects all the chocolates there.
// If both robots land on the same cell, the chocolates in that cell are collected only once.
// Robots cannot move outside the boundaries of the grid.
// Both robots must continue moving until they reach the bottom row of the grid.
//   int dx[3]={1,1,1};
//   int dy[3]={-1,0,1};//From a cell (i, j), robots can move to cell (i + 1, j - 1), (i + 1, j), or (i + 1, j + 1).
  int dx[3]={1,1,1};
  int dy[3]={-1,0,1};//From a cell (i, j), robots can move to cell (i + 1, j - 1), (i + 1, j), or (i + 1, j + 1).
    int maxChocolate(vector<vector<int>>& mat) {
        // code here
         // robot1 starts at (0,0)
         // robot2 starts at (0,m-1)
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,INT_MIN)));
        // Base: last row
        // Base: all (c1, c2) pairs in last row
        for(int c1=0; c1<m; c1++){
            for(int c2=0; c2<m; c2++){
                if(mat[n-1][c1] == -1 || mat[n-1][c2] == -1) continue;
                if(c1 == c2) dp[n-1][c1][c2] = mat[n-1][c1];
                else dp[n-1][c1][c2] = mat[n-1][c1] + mat[n-1][c2];
            }
        }

        // Fill from row = n-2 down to 0
        for(int r1=n-2; r1>=0; r1--){
            for(int c1=0; c1<m; c1++){
                for(int c2=0; c2<m; c2++){
                     int r2=r1;
                      
                    int add=0;
                  if(r1 == r2 && c1 == c2) add = mat[r1][c1];
                  else add = mat[r1][c1] + mat[r2][c2];

                    int sum = INT_MIN;

                    // 9 transitions
                    for(int k1=0; k1<3; k1++){
                        int nc1 = c1 + dy[k1];

                        for(int k2=0; k2<3; k2++){
                            int nc2 = c2 + dy[k2];

                            if(nc1 < 0 || nc1 >= m) continue;
                            if(nc2 < 0 || nc2 >= m) continue;

                            if(dp[r1+1][nc1][nc2] == INT_MIN) continue;

                            sum = max(sum, dp[r1+1][nc1][nc2]);
                        }
                    }

                    if(sum == INT_MIN) dp[r1][c1][c2] = INT_MIN;
                    else dp[r1][c1][c2] = add + sum;
                }
            }
        }
        return dp[0][0][m-1];
    }
};



class Solution {
public:
int f(int i,int j1,int j2,int m,int n,vector<vector<int>>& grid,vector<vector<vector<int>>>& dp) {
    if (j1 < 0 || j1 >= n || j2 < 0 || j2 >= n) {
        return -1e8;
    }
    if (i ==m-1) {
        if (j1==j2) return grid[i][j1];
        else return grid[i][j1] + grid[i][j2];
    }
    
    if (dp[i][j1][j2] != -1) return dp[i][j1][j2];
    int maxi = -1e8; 
        for(int dj1=-1;dj1<=1;dj1++){
            for(int dj2=-1;dj2<=1;dj2++){
            int value=0;
            value = grid[i][j1];
            if (j1 != j2)value=grid[i][j1] + grid[i][j2];
            maxi=max(maxi,value+f(i+1,j1+dj1,j2+dj2,m,n,grid,dp));
        }
            }
    return dp[i][j1][j2]=maxi;
}
    int cherryPickup(vector<vector<int>>& grid) {
    int m=grid.size();
    int n=grid[0].size();
    vector<vector<int>>front(n,vector<int>(n));
    vector<vector<int>>curr(n,vector<int>(n));
    for(int j1=0;j1<n;j1++){
        for(int j2=0;j2<n;j2++){
            if(j1==j2){
            front[j1][j2]=grid[m-1][j1];
            }
            else front[j1][j2]=grid[m-1][j1] + grid[m-1][j2];
        }
    }
    int maxi = -1e8; 
    for(int i=m-2;i>=0;i--){
        for(int j1=0;j1<n;j1++){
            for(int j2=0;j2<n;j2++){
           int maxi = -1e8; 
        for(int dj1=-1;dj1<=1;dj1++){
            for(int dj2=-1;dj2<=1;dj2++){
            int value=0;
            value = grid[i][j1];
            if (j1 != j2)value=grid[i][j1] + grid[i][j2];
            if(j1+dj1>=0 && j1+dj1<n && j2+dj2>=0 && j2+dj2<n){
            value= value + front[j1+dj1][j2+dj2];
            }
            else value+=-1e8;
            maxi=max(maxi,value);
        }
            }
            curr[j1][j2]=maxi;
        }
    }
        front=curr;
    }
    return front[0][n-1];
    }
};