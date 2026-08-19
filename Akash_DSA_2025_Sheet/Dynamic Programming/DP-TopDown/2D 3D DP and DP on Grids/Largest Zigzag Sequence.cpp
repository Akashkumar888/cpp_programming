
class Solution {
  public:
    int solve(int i, int j, int n,vector<vector<int>>& mat,vector<vector<int>>& dp) {
        // Last row
        if(i == n - 1) return mat[i][j];

        // Already calculated
        if(dp[i][j] != -1)return dp[i][j];
        int best = 0;
        // Move to next row
        // But next column must be different
        for(int nextCol = 0; nextCol < n; nextCol++) {
            if(nextCol == j)continue;
            best = max(best, mat[i][j] + solve(i + 1, nextCol, n, mat, dp));
        }
        return dp[i][j] = best;
    }
    int zigzagSequence(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int ans = 0;
        // Sequence can start from any column
        for(int j = 0; j < n; j++) {
            ans = max(ans, solve(0, j, n, mat, dp));
        }
        return ans;
    }
};



class Solution {
  public:

    int zigzagSequence(vector<vector<int>>& mat) {

        int n = mat.size();

        // dp[j] = maximum sum of a zigzag sequence
        // ending at column j in the current row
        vector<int> dp(n);

        // Base case: first row
        for(int j = 0; j < n; j++) {
            dp[j] = mat[0][j];
        }

        // Process remaining rows
        for(int i = 1; i < n; i++) {

            // Find largest and second largest
            // value from previous row
            int maxi1 = -1;
            int maxi2 = -1;
            int index1 = -1;

            for(int j = 0; j < n; j++) {

                if(dp[j] > maxi1) {

                    // Current maximum becomes second maximum
                    maxi2 = maxi1;

                    // Update maximum
                    maxi1 = dp[j];

                    // Store its column
                    index1 = j;
                }
                else if(dp[j] > maxi2) {

                    // Update second maximum
                    maxi2 = dp[j];
                }
            }

            vector<int> curr(n);

            // Calculate DP for current row
            for(int j = 0; j < n; j++) {

                int best;

                // We cannot come from the same column
                if(j == index1)
                    best = maxi2;
                else
                    best = maxi1;

                curr[j] = mat[i][j] + best;
            }

            // Current row becomes previous row
            dp = curr;
        }

        // Maximum answer can end at any column
        return *max_element(dp.begin(), dp.end());
    }
};