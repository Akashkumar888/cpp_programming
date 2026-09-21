
class Solution {
public:
    int solve(int i, int prev, vector<vector<int>>& mat,vector<vector<int>>& dp) {
        int n = mat.size();
        // All rows processed
        if(i == n) return 0;

        // prev + 1 because prev can be -1
        if(dp[i][prev + 1] != -1) {
            return dp[i][prev + 1];
        }
        int ans = INT_MAX;
        // Try all 3 choices
        for(int choice = 0; choice < 3; choice++) {
            // Cannot select same choice
            // as previous row
            if(choice != prev) {
                ans = min(ans,mat[i][choice] + solve(i + 1, choice, mat, dp));
            }
        }
        return dp[i][prev + 1] = ans;
    }
    int minCost(vector<vector<int>>& mat) {
        int n = mat.size();
        // prev can be -1, 0, 1, 2
        vector<vector<int>> dp(n,vector<int>(4, -1));
        return solve(0, -1, mat, dp);
    }
};


class Solution {
public:
    int minCost(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<vector<int>> dp(n,vector<int>(3, 0) );

        // First row
        dp[0][0] = mat[0][0];
        dp[0][1] = mat[0][1];
        dp[0][2] = mat[0][2];
        for(int i = 1; i < n; i++) {
            // Select choice 0
            dp[i][0] = mat[i][0] +min(dp[i - 1][1], dp[i - 1][2]);

            // Select choice 1
            dp[i][1] = mat[i][1] + min(dp[i - 1][0],dp[i - 1][2]);

            // Select choice 2
            dp[i][2] = mat[i][2] +min(dp[i - 1][0],dp[i - 1][1]);
        }

        return min(dp[n - 1][0],min(dp[n - 1][1],dp[n - 1][2]));
    }
};



class Solution {
public:
    int minCost(vector<vector<int>>& mat) {
        int n = mat.size();
        // Previous row costs
        int prev0 = mat[0][0];
        int prev1 = mat[0][1];
        int prev2 = mat[0][2];
        for(int i = 1; i < n; i++) {
            // Current row
            int curr0 = mat[i][0] + min(prev1, prev2);

            int curr1 = mat[i][1] + min(prev0, prev2);

            int curr2 = mat[i][2] + min(prev0, prev1);
            // Move current row to previous row
            prev0 = curr0;
            prev1 = curr1;
            prev2 = curr2;
        }
        return min(prev0,min(prev1, prev2));
    }
};