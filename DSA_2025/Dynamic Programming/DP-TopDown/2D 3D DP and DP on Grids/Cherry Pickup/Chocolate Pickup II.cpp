

class Solution {
  public:
  int dx[4]={0,1,0,-1};
  int dy[4]={1,0,-1,0};
// single (dx, dy) movement array for both robots.
// And here is the clear, exact reason:
//   ✅ Reason 1 — You are controlling two robots, not one
// ✅ Reason 2 — Your logic requires (r1,c1,r2), but using dx/dy only gives next (r1,c1)

  //think like that do robot from 0,0 to n-1 to n-1 
  // when pass int r1,int c1,int r2,int c2 then i need 4 dp 
  // that's why we use int r1,int c1,int r2
// Two robots move simultaneously:
// Robot1 (forward trip): moves down or right
// Robot2 (backward trip): also moves up/left, but when reinterpreted from (0,0), also becomes down or right
// ✅ That’s why both robots always take the same number of steps.
// at any time r1+c1=r2+c2;
// r1,c1 = robot1 position
// r2,c2 = robot2 position (c2 derived)
  int solve(int r1,int c1,int r2,int n,vector<vector<int>>&mat,vector<vector<vector<int>>>&dp){
      int c2 = r1 + c1 - r2;  // important property
      
      // out of bounds
      if(r1 < 0 || c1 < 0 || r2 < 0 || c2 < 0 || r1 >= n || c1 >= n || r2 >= n || c2 >= n)return INT_MIN;
      
      // blocked
      if(mat[r1][c1]==-1 || mat[r2][c2]==-1)return INT_MIN;
      
      // reached bottom-right
        if (r1 == n-1 && c1 == n-1)
            return mat[r1][c1];
      
        if(dp[r1][c1][r2]!=-2)return dp[r1][c1][r2];
        
        int sum=INT_MIN;// because max cell value need 
        
      // chocolates collected
        int add = 0;
        if (r1 == r2 && c1 == c2) add = mat[r1][c1];      // same cell → count once
        else add = mat[r1][c1] + mat[r2][c2];
            
        // 4 valid transitions:

        // 1) robot1 ↓, robot2 ↓
        sum = max(sum, solve(r1+1,c1,r2+1,n,mat,dp));
        // 2) robot1 ↓, robot2 →
        sum = max(sum, solve(r1+1,c1,r2,n,mat,dp));
        // 3) robot1 →, robot2 ↓
        sum = max(sum, solve(r1,c1+1,r2+1,n,mat,dp));
        // 4) robot1 →, robot2 →
        sum = max(sum, solve(r1,c1+1,r2,n,mat,dp));

        if (sum == INT_MIN) return dp[r1][c1][r2] = INT_MIN;

      return dp[r1][c1][r2]=sum+add;
  }
    int chocolatePickup(vector<vector<int>> &mat) {
        // code here
        int n=mat.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector<int>(n+1,-2)));
        int ans=solve(0,0,0,n,mat,dp);
        return ans==INT_MIN ? 0: ans;
    }
};


class Solution {
  public:
  int dx[4]={0,1,0,-1};
  int dy[4]={1,0,-1,0};
// single (dx, dy) movement array for both robots.
// And here is the clear, exact reason:
//   ✅ Reason 1 — You are controlling two robots, not one
// ✅ Reason 2 — Your logic requires (r1,c1,r2), but using dx/dy only gives next (r1,c1)

  //think like that do robot from 0,0 to n-1 to n-1 
  // when pass int r1,int c1,int r2,int c2 then i need 4 dp 
  // that's why we use int r1,int c1,int r2
// Two robots move simultaneously:
// Robot1 (forward trip): moves down or right
// Robot2 (backward trip): also moves up/left, but when reinterpreted from (0,0), also becomes down or right
// ✅ That’s why both robots always take the same number of steps.
// at any time r1+c1=r2+c2;
// r1,c1 = robot1 position
// r2,c2 = robot2 position (c2 derived)
    int chocolatePickup(vector<vector<int>> &mat) {
        // code here
        int n=mat.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector<int>(n,INT_MIN)));
        // Base case: last cell
      // Base case: last cell (n-1, n-1)
        dp[n-1][n-1][n-1] = (mat[n-1][n-1] == -1 ? INT_MIN : mat[n-1][n-1]);

      // Fill from bottom to top
      for(int r1 = n-1; r1 >= 0; r1--){
          for(int c1 = n-1; c1 >= 0; c1--){
              for(int r2 = n-1; r2 >= 0; r2--){

                  int c2 = r1 + c1 - r2; 
                  if(c2 < 0 || c2 >= n) continue;

                  if(mat[r1][c1] == -1 || mat[r2][c2] == -1) continue;

                  if(r1 == n-1 && c1 == n-1 && r2 == n-1 && c2==n-1) continue;

                  int add=0;
                  if(r1 == r2 && c1 == c2) add = mat[r1][c1];
                  else add = mat[r1][c1] + mat[r2][c2];
                  
                  int sum = INT_MIN;

                  // 4 transitions:
                  // 1) robot1 ↓ , robot2 ↓
                  if(r1+1 < n && r2+1 < n){
                      sum = max(sum, dp[r1+1][c1][r2+1]);
                  }
                  // 2) robot1 ↓ , robot2 →
                  if(r1+1 < n){
                      sum = max(sum, dp[r1+1][c1][r2]);
                  }
                  // 3) robot1 → , robot2 ↓
                  if(c1+1 < n && r2+1 < n){
                      sum = max(sum, dp[r1][c1+1][r2+1]);
                  }
                  // 4) robot1 → , robot2 →
                  if(c1+1 < n){
                      sum = max(sum, dp[r1][c1+1][r2]);
                  }

                  if(sum == INT_MIN){
                      dp[r1][c1][r2] = INT_MIN;
                      continue;
                  }

                  dp[r1][c1][r2] = sum + add;
              }
          }
      }
      return dp[0][0][0] == INT_MIN ? 0 : dp[0][0][0];
    }
};