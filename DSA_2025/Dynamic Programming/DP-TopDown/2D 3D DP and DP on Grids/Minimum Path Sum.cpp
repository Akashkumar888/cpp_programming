
class Solution {
public:
// only move either down or right at any point in time.
// here i start (m-1,n-1) top down approach then up or left use  
int solve(int i,int j,vector<vector<int>>& grid,vector<vector<int>>&dp){
  if(i==0 && j==0)return grid[0][0]; // loop me es condition ko if me linkhenge 
  if(i<0||j<0)return INT_MAX;
  if(dp[i][j]!=-1)return dp[i][j];
  // loop me es condition ko else me linkhenge 
//  recursive calls
        int left=solve(i,j-1,grid,dp);
        int up=solve(i-1,j,grid,dp);
        // if both directions impossible → return INT_MAX (do NOT add grid[i][j])
        if(left==INT_MAX && up==INT_MAX)return dp[i][j]=INT_MAX;
        // SAFE addition (no overflow)
        int minPathSum=min(left,up)+grid[i][j];
        return dp[i][j]=minPathSum;
}
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n+1,-1));
        return solve(m-1,n-1,grid,dp); // same  (m-1,n-1) bottom up code me rahega bs dp[m-1][n-1];
    }
};

class Solution {
public:
// only move either down or right at any point in time.
// here i start (m-1,n-1) top down approach then up or left use  
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n+1,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0)dp[i][j]=grid[0][0];
                else{
                    // loop me es condition ko else me linkhenge 
                   //  recursive calls
                   int left=INT_MAX,up=INT_MAX;
                    if(j>0)left=dp[i][j-1];
                    if(i>0)up=dp[i-1][j];
                    // if both directions impossible → return INT_MAX (do NOT add grid[i][j])
                    if(left==INT_MAX && up==INT_MAX)return dp[i][j]=INT_MAX;
                    // SAFE addition (no overflow)
                    int minPathSum=min(left,up)+grid[i][j];
                    dp[i][j]=minPathSum;
                }
            }
        }
        return dp[m-1][n-1]; // same  (m-1,n-1) bottom up code me rahega bs dp[m-1][n-1];
    }
};


class Solution {
public:
// only move either down or right at any point in time.
// here i start (m-1,n-1) top down approach then up or left use  
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int>prev(n,0),temp(n,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0)temp[j]=grid[0][0];
                else{
                    // loop me es condition ko else me linkhenge 
                   //  recursive calls
                   int left=INT_MAX,up=INT_MAX;
                    if(j>0)left=temp[j-1];
                    if(i>0)up=prev[j];
                    // if both directions impossible → return INT_MAX (do NOT add grid[i][j])
                    if(left==INT_MAX && up==INT_MAX)return temp[j]=INT_MAX;
                    // SAFE addition (no overflow)
                    int minPathSum=min(left,up)+grid[i][j];
                    temp[j]=minPathSum;
                }
            }
            prev=temp;
        }
        return prev[n-1]; // same  (m-1,n-1) bottom up code me rahega bs dp[m-1][n-1];
    }
};

