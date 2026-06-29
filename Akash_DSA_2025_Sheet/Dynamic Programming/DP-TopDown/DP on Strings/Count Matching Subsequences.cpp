
class Solution {
  public:
    int MOD = 1e9+7;
    int solve(int i, int j, string &s1, string &s2, vector<vector<int>> &dp){
        if(j < 0) return 1;
        if(i < 0) return 0;
            
        if(dp[i][j] != -1) return dp[i][j];
            
        int same = 0, notsame = 0;
        // got both char same -> two cases pick it both pointer move forward and not pick it only i will move
        if(s1[i] == s2[j]) same = solve(i-1,j-1,s1,s2,dp) + solve(i-1,j,s1,s2,dp);
        
        else notsame = solve(i-1,j,s1,s2,dp);
        // didn't get the same element -> just move the i pointer to find that element
            
        return dp[i][j] = (same + notsame) % MOD;
    }
    int countWays(string &s1, string &s2) {
        // code here
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(n-1,m-1,s1,s2,dp);
    }
};



class Solution {
  public:
    int MOD = 1e9+7;
    int countWays(string &s1, string &s2) {
        // code here
        int n = s1.size();
        int m = s2.size();
        vector<vector<unsigned long long>> dp(n+1,vector<unsigned long long>(m+1,0));
        for(int i=0;i<=n;i++)dp[i][0]=1;
        for(int j=1;j<=m;j++)dp[0][j]=0;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                int same = 0, notsame = 0;
                // got both char same -> two cases pick it both pointer move forward and not pick it only i will move
                if(s1[i-1] == s2[j-1]) same = dp[i-1][j-1] + dp[i-1][j] ;
                
                else notsame = dp[i-1][j];
                // didn't get the same element -> just move the i pointer to find that element
                    
                dp[i][j] = (same + notsame) % MOD;
            }
        }
        return (int)dp[n][m];  // final answer fits
    }
};