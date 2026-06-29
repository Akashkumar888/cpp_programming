
class Solution {
  public:
    int solve(int i,int j,vector<int>&a,vector<int>&b,vector<vector<int>>&dp){
        // Impossible
        if(i < j) return -1e9;

        // Only b[0] left
        if(j == 0){
            int ans = 0;
            for(int k = 0; k <= i; k++){
                ans = max(ans,a[k]*b[0]);
            }
            return ans;
        }

        if(dp[i][j] != -1) return dp[i][j];

        // Skip a[i]
        int notPick = solve(i-1,j,a,b,dp);

        // Match a[i] with b[j]
        int pick = a[i]*b[j] + solve(i-1,j-1,a,b,dp);

        return dp[i][j] = max(pick,notPick);
    }
    int maxDotProduct(vector<int>& a, vector<int>& b) {
        int n = a.size();
        int m = b.size();
        vector<vector<int>> dp(n, vector<int>(m,-1));
        return solve(n-1,m-1,a,b,dp);
    }
};



class Solution {
  public:
    int maxDotProduct(vector<int>& a, vector<int>& b) {
        int n = a.size();
        int m = b.size();
        vector<vector<int>> dp(n, vector<int>(m, INT_MIN));
        // Base case: only b[0]
        for(int i = 0; i < n; i++){
            int ans = 0;
            for(int k = 0; k <= i; k++){
                ans = max(ans, a[k] * b[0]);
            }
            dp[i][0] = ans;
        }

        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                if(j > i) continue;
                int notPick = dp[i-1][j];
                int pick = INT_MIN;
                if(dp[i-1][j-1] != INT_MIN){
                    pick = a[i] * b[j] + dp[i-1][j-1];
                }
                dp[i][j] = max(pick, notPick);
            }
        }
        return dp[n-1][m-1];
    }
};