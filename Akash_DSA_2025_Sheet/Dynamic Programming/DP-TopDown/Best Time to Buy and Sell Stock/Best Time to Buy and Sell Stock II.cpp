
class Solution {
public:
// question said start from left to right 
// On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can sell and buy the stock multiple times on the same day, ensuring you never hold more than one share of the stock.
  int solve(int i,int n,bool buy,vector<int>&prices,vector<vector<int>>&dp){
      if(i>=n)return 0;
      int pick=0;
      int notpick=0;
      if(dp[i][buy]!=-1)return dp[i][buy];
      if(buy){ // buy conditions 
          pick=solve(i+1,n,false,prices,dp)-prices[i];
          notpick=solve(i+1,n,true,prices,dp);
      }
      else{ // sell conditions 
          pick=solve(i+1,n,true,prices,dp)+prices[i]; 
          notpick=solve(i+1,n,false,prices,dp);
      }
      return dp[i][buy]=max(pick,notpick);
  }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        bool buy=true;
        return solve(0,n,buy,prices,dp);
    }
};

class Solution {
public:
// question said start from left to right 
// On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can sell and buy the stock multiple times on the same day, ensuring you never hold more than one share of the stock.
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        // base case 
        dp[n][0]=dp[n][1]=0;
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<2;buy++){
                int pick=0;
                int notpick=0;
                if(buy){ // buy conditions 
                    pick=dp[i+1][0] - prices[i]; // false -> 0
                    notpick=dp[i+1][1];// true -> 1
                }
                else{ // sell conditions 
                    pick=dp[i+1][1] + prices[i]; 
                    notpick=dp[i+1][0];
                }
                dp[i][buy]=max(pick,notpick);
            }
        }
        return dp[0][1];// we start with buy state = true
    }
};

class Solution {
public:
// question said start from left to right 
// On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can sell and buy the stock multiple times on the same day, ensuring you never hold more than one share of the stock.
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int>ahead(2,0),curr(2,0);
        // base case 
        ahead[0]=ahead[1]=0;
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<2;buy++){
                int pick=0;
                int notpick=0;
                if(buy){ // buy conditions 
                    pick=ahead[0] - prices[i]; // false -> 0
                    notpick=ahead[1];// true -> 1
                }
                else{ // sell conditions 
                    pick=ahead[1] + prices[i]; 
                    notpick=ahead[0];
                }
                curr[buy]=max(pick,notpick);
            }
            ahead=curr;
        }
        return ahead[1];// we start with buy state = true
    }
};

class Solution {
public:
// question said start from left to right 
// On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can sell and buy the stock multiple times on the same day, ensuring you never hold more than one share of the stock.
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        // ahead[0] means aheadNotBuy
        // ahead[1] means aheadBuy
        int aheadNotBuy=0;
        int aheadBuy=0;
        for(int i=n-1;i>=0;i--){
                 // buy conditions 
                // false -> 0
                // true -> 1
                // If we can buy today
                int currBuy=max(aheadNotBuy - prices[i],aheadBuy);
                // sell conditions 
                 // If we must sell today
                int currNotBuy=max(aheadBuy + prices[i],aheadNotBuy);
            aheadBuy=currBuy;
            aheadNotBuy=currNotBuy;
        }
        return aheadBuy;// we start with buy state = true
    }
};

