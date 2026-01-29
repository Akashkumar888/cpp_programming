
class Solution {
public:
//   You need to determine the maximum possible amount of money you can win if you go first.
// Note: Both the players are playing optimally. -> use DP
// when it's your turn
//do your best (max)
// when it's your opponent turn
// expect the worst from the result (min)
// min max game strategy
  int solve(int i,int j,vector<int>&piles,vector<vector<int>>&dp){
      if(i>j)return 0;
      if(i==j)return piles[i];// piles[j]
      if(dp[i][j]!=-1)return dp[i][j];
      // recurion for player 1
      int take_i=piles[i]+min(solve(i+2,j,piles,dp),solve(i+1,j-1,piles,dp));
      int take_j=piles[j]+min(solve(i+1,j-1,piles,dp),solve(i,j-2,piles,dp));
      return dp[i][j]=max(take_i,take_j);//the maximum possible amount of money you can win if you go first
  }
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        int totalSum=accumulate(piles.begin(),piles.end(),0);
        int player1Sum=solve(0,n-1,piles,dp);
        int player2Sum=totalSum-player1Sum;
        return player1Sum>=player2Sum;
    }
};

class Solution {
public:
//   You need to determine the maximum possible amount of money you can win if you go first.
// Note: Both the players are playing optimally. -> use DP
// when it's your turn
//do your best (max)
// when it's your opponent turn
// expect the worst from the result (min)
// min max game strategy
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        // base case: same index
        for (int i=0;i<n;i++) dp[i][i] = piles[i];
        // base case: two elements
        for (int i=0;i+1<n;i++)dp[i][i+1]=max(piles[i],piles[i+1]);
        // bottom-up in YOUR style:
        // i from n-1 → 0
        // j from i+2 → n-1
        for(int i=n-1;i>=0;i--){
            for(int j=i+2;j<n; j++){

                int left1=dp[i+2][j];     // solve(i+2, j)
                int left2=dp[i+1][j-1];   // solve(i+1, j-1)
                int take_i=piles[i]+min(left1,left2);

                int right1=dp[i+1][j-1];  // solve(i+1, j-1)
                int right2=dp[i][j-2];    // solve(i, j-2)
                int take_j=piles[j]+min(right1,right2);

                dp[i][j]=max(take_i, take_j);
            }
        }
        int totalSum=accumulate(piles.begin(),piles.end(),0);
        int player1Sum=dp[0][n-1];
        int player2Sum=totalSum-player1Sum;
        return player1Sum>=player2Sum;
    }
};

class Solution {
public:
//   You need to determine the maximum possible amount of money you can win if you go first.
// Note: Both the players are playing optimally. -> use DP
// when it's your turn
//do your best (max)
// when it's your opponent turn
// expect the worst from the result (min)
// min max game strategy
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        vector<int> prev2(n,0), prev1(n,0), temp(n,0);

        // i = n-1 (base case)
        for(int j=0; j<n; j++)
            temp[j] = (j == n-1 ? piles[n-1] : 0);

        prev1 = temp;   // dp[i+1]

        // i = n-2 (base case)
        for(int j=0; j<n; j++) {
            if(j == n-2) temp[j] = piles[n-2];
            else if(j == n-1) temp[j] = max(piles[n-2], piles[n-1]);
            else temp[j] = 0;
        }

        prev2 = prev1;  // dp[i+2]
        prev1 = temp;   // dp[i+1]

        // i from n-3 → 0
        for(int i=n-3; i>=0; i--) {

            // dp[i][i]
            temp[i] = piles[i];

            // dp[i][i+1]
            temp[i+1] = max(piles[i], piles[i+1]);

            for(int j=i+2; j<n; j++) {

                int left1 = prev2[j];      // dp[i+2][j]
                int left2 = prev1[j-1];    // dp[i+1][j-1]
                int take_i = piles[i] + min(left1, left2);

                int right1 = prev1[j-1];   // dp[i+1][j-1]
                int right2 = temp[j-2];    // dp[i][j-2]
                int take_j = piles[j] + min(right1, right2);

                temp[j] = max(take_i, take_j);
            }

            prev2 = prev1;
            prev1 = temp;
        }

        int player1Sum=temp[n-1];
        int totalSum=accumulate(piles.begin(),piles.end(),0);
        int player2Sum=totalSum-player1Sum;
        return player1Sum>=player2Sum;
    }
};