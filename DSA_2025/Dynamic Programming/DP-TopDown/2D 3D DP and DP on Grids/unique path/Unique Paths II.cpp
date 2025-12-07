
class Solution {
public:
// down or right at any point in time.
// here i start (m-1,n-1) top down approach then up or left use  
// An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.
int dx[2]={-1,0};
int dy[2]={0,-1};
int solve(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&dp){
  if(i<0||j<0 ||grid[i][j]==1)return 0;
  if(i==0 && j==0)return 1; // loop me es condition ko if me linkhenge 
  if(dp[i][j]!=-1)return dp[i][j];
  // loop me es condition ko else me linkhenge 
  int countPath=0;
  for(int k=0;k<2;k++){
    int ni=i+dx[k];
    int nj=j+dy[k];
    countPath+=solve(ni,nj,grid,dp);
  }
  return dp[i][j]=countPath;
}
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>>dp(m,vector<int>(n+1,-1));
        return solve(m-1,n-1,obstacleGrid,dp); // same  (m-1,n-1) bottom up code me rahega bs dp[m-1][n-1];
    }
};

class Solution {
public:
// down or right at any point in time.
// here i start (m-1,n-1) top down approach then up or left use  
// An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.
int dx[2]={-1,0};
int dy[2]={0,-1};
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1)return 0;// agar starting point pr hi stone ho tb
        vector<vector<int>>dp(m,vector<int>(n+1,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0)dp[i][j]=1;
                else if(obstacleGrid[i][j]==1)dp[i][j]=0;
                else{ // loop me es condition ko else me linkhenge 
                int countPath=0;
                for(int k=0;k<2;k++){
                    int ni=i+dx[k];
                    int nj=j+dy[k];
                    if(ni>=0 && nj>=0)countPath+=dp[ni][nj];
                }
                dp[i][j]=countPath;
                }
            }
        }
        return dp[m-1][n-1];// same  (m-1,n-1) bottom up code me rahega bs dp[m-1][n-1];
    }
};

// down or right at any point in time.
// here i start (m-1,n-1) top down approach then up or left use 
// int dx[2]={-1,0};
// int dy[2]={0,-1}; is array ke sath space optimised nhi ho pata isliye simple recursion likho
// taki prev , temp use ho sake
// We can move only down or right.
// In a pure recursive top-down approach, we would start from (m-1, n-1)
// and move to (m-2, n-1) [up] or (m-1, n-2) [left].
// That means dx = {-1, 0}, dy = {0, -1}.
//
// But using these dx, dy moves makes space optimization harder,
// because top and left values come from different DP rows.
//
// Therefore, instead of recursion, we use space-optimized tabulation
// with only two arrays: prev (previous row) and temp (current row).
//
// temp[j]  = ways from left  (i, j-1)
// prev[j]  = ways from up    (i-1, j)
//
// This gives us O(m*n) time and O(n) space.
// An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.
class Solution {
public: 
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1)return 0;// agar starting point pr hi stone ho tb
        // We can move only down or right.
        // A recursive top-down solution would start from (m-1, n-1)
        // and move "up" or "left".
        // But recursion makes space optimization harder.
        // So we use a space-optimized DP with prev (top row) and temp (current row).
        vector<int> prev(n,0),temp(n,0); // temp ko ek bar hi declare and initialize karo
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0)temp[j]=1;
                else if(obstacleGrid[i][j]==1)temp[j]=0;
                else{ // loop me es condition ko else me linkhenge 
                int countPath=0;
                for(int k=0;k<2;k++){
                    int left=0,up=0;
                    if(j>0)left=temp[j-1];// from left
                    if(i>0)up=prev[j];// from top row
                    countPath=left+up;
                }
                temp[j]=countPath;
                }
            }
            prev=temp;
        }
        return prev[n-1];
    }
};


class Solution {
public:
    int f(int i,int j,vector<vector<int>>& obstacleGrid,vector<vector<int>>&dp){
    if(i<0 || j<0 || obstacleGrid[i][j]==1)return 0;
	if(i==0 && j==0)return 1;
	if(dp[i][j]!=-1)return dp[i][j];
	int left=f(i,j-1,obstacleGrid,dp);
	int up=f(i-1,j,obstacleGrid,dp);
	return dp[i][j]=left+up;
}
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m=obstacleGrid.size();
    int n=obstacleGrid[0].size();
    vector<vector<int>>dp(m,vector<int>(n,-1));
	return f(m-1,n-1,obstacleGrid,dp);
    }
};

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m=obstacleGrid.size();
    int n=obstacleGrid[0].size();
    vector<vector<int>>dp(m,vector<int>(n,0));
	// start cell
        if (obstacleGrid[0][0] == 1) return 0;
        dp[0][0] = 1;

        // fill first row
        for (int j = 1; j < n; j++) {
            if (obstacleGrid[0][j] == 1) dp[0][j] = 0;
            else dp[0][j] = dp[0][j-1];
        }

        // fill first column
        for (int i = 1; i < m; i++) {
            if (obstacleGrid[i][0] == 1) dp[i][0] = 0;
            else dp[i][0] = dp[i-1][0];
        }
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
        if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                    continue;
                }
        int left=dp[i][j-1];
	    int up=dp[i-1][j];
	    dp[i][j]=left+up;
        }
    }
    return dp[m-1][n-1];
    }
};


