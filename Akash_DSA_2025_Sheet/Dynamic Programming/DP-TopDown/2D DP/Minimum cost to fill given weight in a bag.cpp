
class Solution {
  public:
    int solve(int i, vector<int>& cost, int W,vector<vector<int>>& dp){
        if(W == 0)return 0;
        if(i == 0){
            if(cost[0] == -1)return 1e9;
            if(W % 1 == 0)return W * cost[0];
            return 1e9;
        }
        if(dp[i][W] != -1)return dp[i][W];
        int notPick = solve(i - 1, cost, W, dp);
        int pick = 1e9;
        int wt = i + 1;
        if(cost[i] != -1 && wt <= W)pick = cost[i] + solve(i, cost, W - wt, dp);
        return dp[i][W] = min(pick, notPick);
    }
    int minimumCost(vector<int> &cost, int W) {
        int n = cost.size();
        vector<vector<int>> dp(n,vector<int>(W + 1, -1));
        int ans = solve(n - 1, cost, W, dp);
        return (ans >= 1e9 ? -1 : ans);
    }
};




class Solution {
  public:
    int minimumCost(vector<int> &cost, int W) {
        int n = cost.size();
        vector<vector<int>> dp(n,vector<int>(W + 1, 1e9));
        for(int w = 0; w <= W; w++){
            if(cost[0] != -1){
                dp[0][w] = w * cost[0];
            }
        }
        dp[0][0] = 0;
        for(int i = 1; i < n; i++){
            int wt = i + 1;
            for(int w = 0; w <= W; w++){
                int notPick = dp[i - 1][w];
                int pick = 1e9;
                if(cost[i] != -1 && wt <= w){
                    pick = cost[i] + dp[i][w - wt];
                }
                dp[i][w] = min(pick, notPick);
            }
        }
        return dp[n - 1][W] >= 1e9 ? -1 : dp[n - 1][W];
    }
};
