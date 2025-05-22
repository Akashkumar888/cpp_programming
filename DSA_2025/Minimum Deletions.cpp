
class Solution {
public:
int f(int i,int j,string &s,string &t,vector<vector<int>>&dp){
 if(i<0 || j<0)return 0;
 if(dp[i][j]!=-1)return dp[i][j];
 if(s[i]==t[j]){
	 return dp[i][j]= 1+ f(i-1,j-1,s,t,dp);
 }
return dp[i][j] = 0+max(f(i-1,j,s,t,dp),f(i,j-1,s,t,dp));
}
    int longestCommonSubsequence(string s, string t) {
    int m=s.size();
	int n=t.size();
	vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
    return f(m-1,n-1,s,t,dp);
    // vector<int>prev(n+1,0),curr(n+1,0);
    // for(int j=0;j<=n;j++)prev[j]=0;

    // for(int i=1;i<=m;i++){
    //    for(int j=1;j<=n;j++){
    //     if(s[i-1]==t[j-1]){
	//     curr[j]= 1+prev[j-1];
    //     }
    //    else
    //   curr[j]= 0 + max(prev[j],curr[j-1]);
    //    }
    //    prev=curr;
    //    }
    // return prev[n];
    }
};












class Solution {
public:
int f(int i,int j,string &s,string &t,vector<vector<int>>&dp){
    if(i<0 || j<0)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    if(s[i]==t[j]) {
        return dp[i][j]=   1+f(i-1,j-1,s,t,dp);
    }
    return  dp[i][j]= 0+max(f(i-1,j,s,t,dp),f(i,j-1,s,t,dp));
}
    int longestPalindromeSubseq(string s) {
        int m=s.size();
        string t=s;
        vector<vector<int>>dp(m,vector<int>(m+1,-1));
        reverse(t.begin(),t.end());
        return f(m-1,m-1,s,t,dp);
    }
};





class Solution {
  public:
  int solve(int i,int j,string &s,string &t,vector<vector<int>>&dp){
      if(i<0 || j<0)return 0;
      if(dp[i][j]!=-1)return dp[i][j];
      if(s[i]==t[j]){
          return dp[i][j]=1+solve(i-1,j-1,s,t,dp);
      }
      return dp[i][j]=0+max(solve(i-1,j,s,t,dp),solve(i,j-1,s,t,dp));
  }
    int minDeletions(string s) {
        // code here
        int n=s.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        string t=s;
        reverse(t.begin(),t.end());
        return n-solve(n-1,n-1,s,t,dp);
    }
};

 