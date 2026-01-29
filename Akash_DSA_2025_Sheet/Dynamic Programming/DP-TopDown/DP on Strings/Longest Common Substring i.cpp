
class Solution {
public:
    int ans;
    int solve(int i, int j, string &s1, string &s2,
              vector<vector<int>>& dp) {
        if(i == 0 || j == 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        if(s1[i-1] == s2[j-1]) {
            dp[i][j] = 1 + solve(i-1, j-1, s1, s2, dp);
            ans = max(ans, dp[i][j]);
        } 
        else {
            dp[i][j] = 0;
        }
        return dp[i][j];
    }

    int longestCommonSubstr(string &s1, string &s2) {
        ans = 0;  // IMPORTANT reset
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));// beacuse dp[n][m] that why [n+1][m+1] use 

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                solve(i, j, s1, s2, dp);
            }
        }
        return ans;
    }
};


// after doing indexing 
// recursion me hr jagah jaha pr string check ho raha hai vaha function me nhi i to i-1 or j to j-1 not in dp
// dp size increase [n+1][m+1] or [m+1][n+1]
// return dp[i][j]= 0+max(solve(i-1,j,s1,s2,dp),solve(i,j-1,s1,s2,dp));  ye else me rahega bottom up ke code me 

class Solution {
  public:
    int longestCommonSubstr(string& s1, string& s2) {
        // code here
        int n=s1.size();
        int m=s2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++)dp[i][0]=0;
        for(int j=1;j<=m;j++)dp[0][j]=0;
        int maxilen=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]= 1+dp[i-1][j-1];
                    maxilen=max(maxilen,dp[i][j]);
                }
                else dp[i][j]=0;// ye else me rahega bottom up me 
            }
        }
        // return dp[n][m];
        return maxilen;
    }
};

class Solution {
  public:
    int longestCommonSubstr(string& s1, string& s2) {
        // your code here
        int n=s1.size();
        int m=s2.size();
        vector<int>prev(m+1,0),temp(m+1,0);
        // for(int i=1;i<=n;i++)dp[i][0]=0;// only use for column but it use row thats wht why we cbt use it.
        for(int j=1;j<=m;j++)prev[j]=0;
        int maxilen=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    temp[j]= 1+prev[j-1];
                    maxilen=max(maxilen,temp[j]);
                }
                else temp[j]=0;// ye else me rahega bottom up me 
            }
            prev=temp;
        }
        return maxilen;
    }
};