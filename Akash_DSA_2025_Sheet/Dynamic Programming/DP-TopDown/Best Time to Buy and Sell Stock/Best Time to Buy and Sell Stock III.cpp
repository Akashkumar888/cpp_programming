
class Solution {
public:
// question said start from left to right 
// On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can sell and buy the stock multiple times on the same day, ensuring you never hold more than one share of the stock.
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
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,
        vector<vector<int>>(2,vector<int>(3,-1))
        );
        bool buy=true;
        int trans=2;
        return solve(0,n,buy,trans,prices,dp);
    }
};

class Solution {
public:
// question said start from left to right 
// On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can sell and buy the stock multiple times on the same day, ensuring you never hold more than one share of the stock.
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n+1,
        vector<vector<int>>(2,vector<int>(3,0))
        );
        
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<2;buy++){
                for(int trans=1;trans<=2;trans++){
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
        return dp[0][1][2];// we start with buy state = true
    }
};

class Solution {
public:
// question said start from left to right 
// On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can sell and buy the stock multiple times on the same day, ensuring you never hold more than one share of the stock.
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>ahead(2,vector<int>(3,0));
        vector<vector<int>>curr(2,vector<int>(3,0));
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<2;buy++){
                for(int trans=1;trans<=2;trans++){
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
        return curr[1][2];// we start with buy state = true
    }
};


class Solution {
public:
// question said start from left to right 
// On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can sell and buy the stock multiple times on the same day, ensuring you never hold more than one share of the stock.
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int> curr(5, 0);  // DP for next day
        for(int i =n - 1; i >= 0; i--){
            vector<int> temp(5, 0);  // DP for current day

            for(int j = 0; j < 4; j++){
                if(j % 2 == 0){
                    // BUY state
                    temp[j] = max(
                        -prices[i] + curr[j + 1],  // buy today
                        curr[j]                    // skip
                    );
                }
                else{
                    // SELL state
                    temp[j] = max(
                        prices[i] + curr[j + 1],   // sell today
                        curr[j]                    // skip
                    );
                }
            }
            curr = temp;
        }
        return curr[0];  // start from first buy
    }
};


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy1 = INT_MIN, sell1 = 0;
        int buy2 = INT_MIN, sell2 = 0;

        for (int &price : prices) {
            // First transaction
            buy1  = max(buy1, -price);          // buy first stock
            sell1 = max(sell1, buy1 + price);   // sell first stock

            // Second transaction
            buy2  = max(buy2, sell1 - price);   // buy second stock
            sell2 = max(sell2, buy2 + price);   // sell second stock
        }

        return sell2;
    }
};

