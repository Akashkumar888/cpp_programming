
class Solution {
  public:
  int solve(int i,int j,string &s,string &t,vector<vector<int>>&dp){
      if(i<0 || j<0)return 0;
      if(dp[i][j]!=-1)return dp[i][j];
      if(s[i]==t[j]){
          return dp[i][j]=1+solve(i-1,j-1,s,t,dp);
      }
      return dp[i][j]= max(solve(i-1,j,s,t,dp),solve(i,j-1,s,t,dp));
  }
    int minSuperSeq(string &s1, string &s2) {
        // code here
        int n=s1.size();
        int m=s2.size();
        vector<vector<int>>dp(n,vector<int>(m+1,-1));
        return (m+n) - solve(n-1,m-1,s1,s2,dp);
    }
};

// index change from 0 to n-1 -> 1 to n 
class Solution {
  public:
  int solve(int i,int j,string &s1,string &s2,vector<vector<int>>&dp){
      if(i==0 || j==0)return 0;
      if(dp[i][j]!=-1)return dp[i][j];
      if(s1[i-1]==s2[j-1]){
          return dp[i][j]=1+solve(i-1,j-1,s1,s2,dp);
      }
      return dp[i][j]= max(solve(i-1,j,s1,s2,dp),solve(i,j-1,s1,s2,dp));
  }
    int minSuperSeq(string &s1, string &s2) {
        // code here
        int n=s1.size();
        int m=s2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return  (m+n) - solve(n,m,s1,s2,dp);
    }
};

class Solution {
  public:
  int solve(int i,int j,string &s1,string &s2,vector<vector<int>>&dp){
      if(i==0 || j==0)return 0;
      if(dp[i][j]!=-1)return dp[i][j];
      if(s1[i-1]==s2[j-1]){
          return dp[i][j]=1+solve(i-1,j-1,s1,s2,dp);
      }
      return dp[i][j]= max(solve(i-1,j,s1,s2,dp),solve(i,j-1,s1,s2,dp));
  }
    int minSuperSeq(string &s1, string &s2) {
        // code here
        int n=s1.size();
        int m=s2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
              else dp[i][j]= max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return (m+n) - dp[n][m];
    }
};

class Solution {
  public:
    int minSuperSeq(string &s1, string &s2) {
        // code here
        int n=s1.size();
        int m=s2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
               else dp[i][j]= max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return (m+n) - dp[n][m];
    }
};

class Solution {
public:
    int minSuperSeq(string &s1, string &s2) {
        int n = s1.size(), m = s2.size();

        vector<int> dp(m + 1, 0);

        for(int i = 1; i <= n; i++) {

            int prevDiagonal = 0;  // this stores dp[i-1][j-1]
            for(int j = 1; j <= m; j++) {

                int temp = dp[j]; // will become dp[i][j] later -> save dp[i-1][j]

                if(s1[i-1] == s2[j-1]) {
                    dp[j] = 1 + prevDiagonal;
                }  
                else {
                    dp[j] = max(dp[j], dp[j-1]); 
                }

                prevDiagonal = temp; // update for next j
            }
        }

        int LCS = dp[m];
        return n + m - LCS;
    }
};
