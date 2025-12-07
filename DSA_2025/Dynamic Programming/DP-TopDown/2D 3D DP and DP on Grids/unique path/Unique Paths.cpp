class Solution {
public:
// down or right at any point in time.
// here i start (m-1,n-1) top down approach then up or left use  
int dx[2]={-1,0};
int dy[2]={0,-1};
int solve(int i,int j,vector<vector<int>>&dp){
  if(i<0||j<0)return 0;
  if(i==0 && j==0)return 1; // loop me es condition ko if me linkhenge 
  if(dp[i][j]!=-1)return dp[i][j];
  // loop me es condition ko else me linkhenge 
  int countPath=0;
  for(int k=0;k<2;k++){
    int ni=i+dx[k];
    int nj=j+dy[k];
    countPath+=solve(ni,nj,dp);
  }
  return dp[i][j]=countPath;
}
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n+1,-1));
        return solve(m-1,n-1,dp); // same  (m-1,n-1) bottom up code me rahega bs dp[m-1][n-1];
    }
};


class Solution {
public:
// down or right at any point in time.
int dx[2]={1,0};
int dy[2]={0,1};
int solve(int i,int j,int m,int n,vector<vector<int>>&dp){
  if(i<0||j<0||i>=m||j>=n)return 0;
  if(i==m-1 && j==n-1)return 1; // loop me es condition ko if me linkhenge 
  if(dp[i][j]!=-1)return dp[i][j];
  // loop me es condition ko else me linkhenge 
  int countPath=0;
  for(int k=0;k<2;k++){
    int ni=i+dx[k];
    int nj=j+dy[k];
    countPath+=solve(ni,nj,m,n,dp);
  }
  return dp[i][j]=countPath;
}
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n+1,-1));
        return solve(0,0,m,n,dp);
    }
};


class Solution {
public:
// down or right at any point in time.
// here i start (m-1,n-1) top down approach then up or left use 
int dx[2]={-1,0};
int dy[2]={0,-1};
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n+1,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0)dp[i][j]=1;
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


class Solution {
public:
int solve(int i,int j,vector<vector<int>>&dp){
    if(i<0 || j<0)return 0;
	if(i==0 && j==0)return 1;
	if(dp[i][j]!=-1)return dp[i][j];
	int left=solve(i,j-1,dp);
	int up=solve(i-1,j,dp);
	return dp[i][j]=left+up;
}
    int uniquePaths(int m, int n) {
    vector<vector<int>>dp(m,vector<int>(n,-1));
	return solve(m-1,n-1,dp);
    }
};

class Solution {
public:
    int uniquePaths(int m, int n) {
    vector<vector<int>>dp(m,vector<int>(n+1,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0)dp[i][j]=1;
                else{ // loop me es condition ko else me linkhenge 
                    int left=0,up=0;
                    if(j>0)left=dp[i][j-1];
                    if(i>0)up=dp[i-1][j];
                    dp[i][j]=left+up;
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

class Solution {
public:
    int uniquePaths(int m, int n) {
        // We can move only down or right.
        // A recursive top-down solution would start from (m-1, n-1)
        // and move "up" or "left".
        // But recursion makes space optimization harder.
        // So we use a space-optimized DP with prev (top row) and temp (current row).
        vector<int> prev(n,0),temp(n,0); // temp ko ek bar hi declare and initialize karo
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 && j == 0) {
                    temp[j] = 1;
                } 
                else {
                    int up = 0, left = 0;
                    if(i > 0) up = prev[j];     // from top row
                    if(j > 0) left = temp[j-1]; // from left
                    temp[j] = up + left;
                }
            }
            prev = temp; // move row forward
        }
        return prev[n-1];
    }
};

class Solution {
public:
    int uniquePaths(int m, int n) {
    int N=n+m-2;
    int r=m-1;
    double res=1;
    for(int i=1;i<=r;i++){
        res=res*(N-r+i)/i;
    }
    return (int)res;
    }
};



class Solution {
public:
int solve(int m,int n,int i,int j,vector<vector<int>>&dp){
    if(i>=m || j>=n)return 0;
    if(i==m-1&&j==n-1)return 1;
    if(dp[i][j]!=-1)return dp[i][j];
    return dp[i][j]=solve(m,n,i+1,j,dp) +solve(m,n,i,j+1,dp);
}
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return solve(m,n,0,0,dp);
    }
};

class Solution {
public:
int dp[101][101];
int solve(int m,int n,int i,int j){
    if(i>=m || j>=n)return 0;
    if(i==m-1 && j==n-1)return 1;
    if(dp[i][j]!=-1)return dp[i][j];
    int down=solve(m,n,i+1,j);
    int right=solve(m,n,i,j+1);
    return dp[i][j]=down+right;
}
    int uniquePaths(int m, int n) {
        memset(dp,-1,sizeof(dp));
        return solve(m,n,0,0);
    }
};

class Solution {
public:
    int uniquePaths(int m, int n) {
    vector<vector<int>>dp(m,vector<int>(n));
    dp[0][0]=1;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
		if(i==0 && j==0){
			dp[0][0]=1;
		}
		else{
        int up=0,left=0;
		if(i>0)up=dp[i-1][j];
		if(j>0)left=dp[i][j-1];
		dp[i][j]=left+up;
		}
		}
	}
	return dp[m-1][n-1];
    }
};

class Solution {
public:
    int uniquePaths(int m, int n) {
   vector<int>prev(n,0);
	for(int i=0;i<m;i++){
		vector<int>curr(n,0);
		for(int j=0;j<n;j++){
		if(i==0 && j==0){
			curr[j]=1;
		}
		else{
        int left=0,up=0;
		if(i>0) up=prev[j];
		if(j>0) left=curr[j-1];
		curr[j]=up+left;
		}
		}
		prev=curr;
	}
	return prev[n-1];
    }
};


