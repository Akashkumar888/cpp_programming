class Solution {
public:
int f(int i,int j,int m,int n,vector<vector<int>>&dp){
    if(i<0 || j<0)return 0;
	if(i==0 && j==0)return 1;
	if(dp[i][j]!=-1)return dp[i][j];
	int left=f(i,j-1,m,n,dp);
	int up=f(i-1,j,m,n,dp);
	return dp[i][j]=left+up;
}
    int uniquePaths(int m, int n) {
    vector<vector<int>>dp(m,vector<int>(n,-1));
	return f(m-1,n-1,0,0,dp);
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