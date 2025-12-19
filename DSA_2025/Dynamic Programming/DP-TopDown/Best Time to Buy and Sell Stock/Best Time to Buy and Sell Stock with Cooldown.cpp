
class Solution {
  public:
//   Stock Buy and Sell with Cooldown
  int solve(int i,int n,bool buy,vector<int>&arr,vector<vector<int>>&dp){
      if(i>=n)return 0;
      int pick=0;
      int notpick=0;
      if(dp[i][buy]!=-1)return dp[i][buy];
      if(buy){ // buy conditions 
          pick=solve(i+1,n,false,arr,dp)-arr[i];
          notpick=solve(i+1,n,true,arr,dp);
      }
      else{ // sell conditions 
          pick=solve(i+2,n,true,arr,dp)+arr[i]; // can't buy right after cell i+2
          notpick=solve(i+1,n,false,arr,dp);
      }
      return dp[i][buy]=max(pick,notpick);
  }
    int maxProfit(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        bool buy=true;
        return solve(0,n,buy,arr,dp);
    }
};


class Solution {
  public:
//   Stock Buy and Sell with Cooldown
    int maxProfit(vector<int>& arr) {
        // code here
        int n=arr.size();
        // dp size = n+2 to safely use dp[i+1], dp[i+2]
        vector<vector<int>>dp(n+2,vector<int>(2,0));
        // bool buy=true;
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<2;buy++){
                int pick=0;
                int notpick=0;
                if(buy){ // buy conditions 
                      pick=dp[i+1][0]-arr[i];//false-> 0
                      notpick=dp[i+1][1];//true-> 1
                  }
                  else{ // sell conditions //true-> 1
                      pick=dp[i+2][1]+arr[i]; // can't buy right after cell i+2
                      notpick=dp[i+1][0];//false-> 0
                  }
                dp[i][buy]=max(pick,notpick);
            }
        }
        return dp[0][1];// we start with buy state = true
    }
};

