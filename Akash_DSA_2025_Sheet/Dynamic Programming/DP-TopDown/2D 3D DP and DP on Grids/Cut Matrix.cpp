
class Solution {
  public:
    int MOD = 1e9 + 7;
    int solve(int r,int c,int pieces,vector<vector<int>>&apple,vector<vector<vector<int>>>&dp,int n,int m){
        // Only one piece left
        if(pieces==1){
            return apple[r][c]>0;
        }
        if(dp[r][c][pieces]!=-1)return dp[r][c][pieces];
        long long ways=0;
        // Horizontal cuts
        for(int i=r+1;i<n;i++){
            // Upper part has at least one 1
            if(apple[r][c]-apple[i][c]>0){
                ways=(ways+
                solve(i,c,pieces-1,
                apple,dp,n,m))%MOD;
            }
        }
        // Vertical cuts
        for(int j=c+1;j<m;j++){
            // Left part has at least one 1
            if(apple[r][c]-apple[r][j]>0){
                ways=(ways+ solve(r,j,pieces-1,apple,dp,n,m))%MOD;
            }
        }
        return dp[r][c][pieces]=ways;
    }
    int findWays(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int m=matrix[0].size();

        // Suffix Sum
        vector<vector<int>> apple(n+1,
        vector<int>(m+1,0));
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                apple[i][j]=matrix[i][j] + apple[i+1][j] + apple[i][j+1] - apple[i+1][j+1];
            }
        }
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(k+1,-1)));
        return solve(0,0,k,apple,dp,n,m);
    }
};




class Solution {
  public:
    int MOD = 1e9 + 7;
    int findWays(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();
        // Suffix sum
        vector<vector<int>> apple(n + 1, vector<int>(m + 1, 0));
        for(int i = n - 1; i >= 0; i--){
            for(int j = m - 1; j >= 0; j--){
                apple[i][j] = matrix[i][j] + apple[i + 1][j] + apple[i][j + 1] - apple[i + 1][j + 1];
            }
        }
        // dp[row][col][pieces]
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m, vector<int>(k + 1, 0)));
        //---------------- Base Case ----------------//
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                // One piece is valid only if this submatrix contains at least one 1
                dp[i][j][1] = (apple[i][j] > 0);
            }
        }
        //---------------- Fill DP ----------------//
        for(int pieces = 2; pieces <= k; pieces++){
            for(int r = n - 1; r >= 0; r--){
                for(int c = m - 1; c >= 0; c--){
                    long long ways = 0;
                    // Horizontal cuts
                    for(int i = r + 1; i < n; i++){
                        // Upper part has at least one 1
                        if(apple[r][c] - apple[i][c] > 0){
                            ways = (ways + dp[i][c][pieces - 1]) % MOD;
                        }
                    }
                    // Vertical cuts
                    for(int j = c + 1; j < m; j++){
                        // Left part has at least one 1
                        if(apple[r][c] - apple[r][j] > 0){
                            ways = (ways + dp[r][j][pieces - 1]) % MOD;
                        }
                    }
                    dp[r][c][pieces] = ways;
                }
            }
        }
        return dp[0][0][k];
    }
};




class Solution {
public:
    static const int MOD = 1000000007;
    int findWays(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();
        //---------------- Suffix Sum ----------------//
        vector<vector<int>> apple(n + 1, vector<int>(m + 1, 0));

        for(int i = n - 1; i >= 0; i--){
            for(int j = m - 1; j >= 0; j--){
                apple[i][j] = matrix[i][j] + apple[i + 1][j] + apple[i][j + 1] - apple[i + 1][j + 1];
            }
        }
        //---------------- DP ----------------//
        vector<vector<vector<int>>> dp(k + 1,vector<vector<int>>(n, vector<int>(m, 0)));
        vector<vector<vector<int>>> down(k + 1,vector<vector<int>>(n + 1, vector<int>(m, 0)));
        vector<vector<vector<int>>> right(k + 1,vector<vector<int>>(n, vector<int>(m + 1, 0)));
        //---------------- Base ----------------//
        for(int i = n - 1; i >= 0; i--){
            for(int j = m - 1; j >= 0; j--){
                dp[1][i][j] = (apple[i][j] > 0);
                down[1][i][j] = (dp[1][i][j] + down[1][i + 1][j]) % MOD;
                right[1][i][j] = (dp[1][i][j] + right[1][i][j + 1]) % MOD;
            }
        }
        //---------------- Pieces ----------------//
        for(int pieces = 2; pieces <= k; pieces++){
            for(int i = n - 1; i >= 0; i--){
                for(int j = m - 1; j >= 0; j--){
                    long long ways = 0;
                    //---------------- Horizontal ----------------//
                    int row = -1;
                    for(int x = i + 1; x < n; x++){
                        if(apple[i][j] - apple[x][j] > 0){
                            row = x;
                            break;
                        }
                    }
                    if(row != -1) ways += down[pieces - 1][row][j];
                    //---------------- Vertical ----------------//
                    int col = -1;
                    for(int y = j + 1; y < m; y++){
                        if(apple[i][j] - apple[i][y] > 0){
                            col = y;
                            break;
                        }
                    }
                    if(col != -1) ways += right[pieces - 1][i][col];
                    dp[pieces][i][j] = ways % MOD;
                }
            }
            //---------------- Rebuild Prefix Arrays ----------------//
            for(int i = n - 1; i >= 0; i--){
                for(int j = m - 1; j >= 0; j--){
                    down[pieces][i][j] = (dp[pieces][i][j] + down[pieces][i + 1][j]) % MOD;
                    right[pieces][i][j] = (dp[pieces][i][j] + right[pieces][i][j + 1]) % MOD;
                }
            }
        }
        return dp[k][0][0];
    }
};