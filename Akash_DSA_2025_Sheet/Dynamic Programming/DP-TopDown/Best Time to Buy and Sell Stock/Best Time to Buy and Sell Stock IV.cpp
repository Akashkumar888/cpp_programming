
class Solution {
public:
  int solve(int i,int n,bool buy,int trans,vector<int>&prices,vector<vector<vector<int>>>&dp){
      if(i>=n)return 0;
      if(trans==0)return 0;
      int pick=0;
      int notpick=0;
      if(dp[i][buy][trans]!=-1)return dp[i][buy][trans];
      if(buy){ // buy conditions 
          pick=solve(i+1,n,false,trans,prices,dp)-prices[i];
          notpick=solve(i+1,n,true,trans,prices,dp);
      }
      else{ // sell conditions 
          pick=solve(i+1,n,true,trans-1,prices,dp)+prices[i]; 
          notpick=solve(i+1,n,false,trans,prices,dp);
      }
      return dp[i][buy][trans]=max(pick,notpick);
  }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,
        vector<vector<int>>(2,vector<int>(k+1,-1))
        );
        bool buy=true;
        int trans=k;
        return solve(0,n,buy,trans,prices,dp);
    }
};


class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n+1,
        vector<vector<int>>(2,vector<int>(k+1,0))
        );
        
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<2;buy++){
                for(int trans=1;trans<=k;trans++){
                    int pick=0;
                    int notpick=0;
                    if(buy){ // buy conditions 
                        pick=dp[i+1][0][trans] - prices[i]; // false -> 0
                        notpick=dp[i+1][1][trans];// true -> 1
                    }
                    else{ // sell conditions 
                        pick=dp[i+1][1][trans-1] + prices[i]; 
                        notpick=dp[i+1][0][trans];
                    }
                    dp[i][buy][trans]=max(pick,notpick);
                }
            }
        }
        return dp[0][1][k];// we start with buy state = true
    }
};

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>ahead(2,vector<int>(k+1,0));
        vector<vector<int>>curr(2,vector<int>(k+1,0));
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<2;buy++){
                for(int trans=1;trans<=k;trans++){
                    int pick=0;
                    int notpick=0;
                    if(buy){ // buy conditions 
                        pick=ahead[0][trans] - prices[i]; // false -> 0
                        notpick=ahead[1][trans];// true -> 1
                    }
                    else{ // sell conditions 
                        pick=ahead[1][trans-1] + prices[i]; 
                        notpick=ahead[0][trans];
                    }
                    curr[buy][trans]=max(pick,notpick);
                }
            }
            ahead=curr;
        }
        return curr[1][k];// we start with buy state = true
    }
};

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(n == 0) return 0;

        vector<int> curr(2*k + 1, 0);

        for(int i = n - 1; i >= 0; i--) {
            vector<int> temp(2*k + 1, 0);

            for(int j = 0; j < 2*k; j++) {
                if(j % 2 == 0) {
                    // BUY state
                    temp[j] = max(
                        -prices[i] + curr[j + 1], // buy
                        curr[j]                   // skip
                    );
                } else {
                    // SELL state
                    temp[j] = max(
                        prices[i] + curr[j + 1],  // sell
                        curr[j]                   // skip
                    );
                }
            }
            curr = temp;
        }
        return curr[0];
    }
};

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n == 0 || k == 0) return 0;

        // Optimization for very large k
        if (k >= n / 2) {
            int profit = 0;
            for (int i = 1; i < n; i++) {
                if (prices[i] > prices[i - 1])
                    profit += prices[i] - prices[i - 1];
            }
            return profit;
        }

        vector<int> buy(k + 1, INT_MIN);
        vector<int> sell(k + 1, 0);

        for (int price : prices) {
            for (int t = 1; t <= k; t++) {
                buy[t]  = max(buy[t], sell[t - 1] - price);
                sell[t] = max(sell[t], buy[t] + price);
            }
        }
        return sell[k];
    }
};
