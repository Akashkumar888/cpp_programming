
class Solution {
  public:
  int solve(int i,vector<int>&val,vector<int>&wt,int W,vector<vector<int>>&dp){
    //   if(W==0)return 0;
      if(i==0){
          if(wt[0]<=W)return val[0];
          else return 0;
      }
      if(dp[i][W]!=-1)return dp[i][W];
      int pick=INT_MIN;
      int notpick=solve(i-1,val,wt,W,dp);
      if(wt[i]<=W)pick=val[i]+solve(i-1,val,wt,W-wt[i],dp);
      return dp[i][W]=max(notpick,pick);
  }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n=val.size();
        vector<vector<int>>dp(n,vector<int>(maxWeight+1,-1));
        return solve(n-1,val,wt,maxWeight,dp);
    }
};

class Solution {
  public:
    int knapsack(int maxWeight, vector<int> &val, vector<int> &wt) {
        // code here
        int n=val.size();
        vector<vector<int>>dp(n,vector<int>(maxWeight+1,0));
        for(int W=wt[0];W<=maxWeight;W++){
            dp[0][W]=val[0];
        }
        for(int i=1;i<n;i++){
            for(int W=0;W<=maxWeight;W++){
                int pick=INT_MIN;
                int notpick=dp[i-1][W];
                if(wt[i]<=W)pick=val[i]+dp[i-1][W-wt[i]];
                dp[i][W]=max(notpick,pick);
            }
        }
        return dp[n-1][maxWeight];
    }
};

class Solution {
  public:
    int knapsack(int maxWeight, vector<int> &val, vector<int> &wt) {
        // code here
        int n=val.size();
        vector<int>prev(maxWeight+1,0),temp(maxWeight+1,0);
        for(int W=wt[0];W<=maxWeight;W++){
            prev[W]=val[0];
        }
        for(int i=1;i<n;i++){
            for(int W=0;W<=maxWeight;W++){
                int pick=INT_MIN;
                int notpick=prev[W];
                if(wt[i]<=W)pick=val[i]+prev[W-wt[i]];
                temp[W]=max(notpick,pick);
            }
            prev=temp;
        }
        return prev[maxWeight];
    }
};

class Solution {
  public:
    int knapsack(int maxWeight, vector<int> &val, vector<int> &wt) {
        // code here
        int n=val.size();
        vector<int>prev(maxWeight+1,0),temp(maxWeight+1,0);
        for(int W=wt[0];W<=maxWeight;W++){
            prev[W]=val[0];
        }
        for(int i=1;i<n;i++){
            for(int W=maxWeight;W>=0;W--){
                int pick=INT_MIN;
                int notpick=prev[W];
                if(wt[i]<=W)pick=val[i]+prev[W-wt[i]];
                temp[W]=max(notpick,pick);
            }
            prev=temp;
        }
        return prev[maxWeight];
    }
};


class Solution {
  public:
    int knapsack(int maxWeight, vector<int> &val, vector<int> &wt) {
        // code here
        int n=val.size();
        vector<int>prev(maxWeight+1,0);
        for(int W=wt[0];W<=maxWeight;W++){
            prev[W]=val[0];
        }
        for(int i=1;i<n;i++){
            for(int W=maxWeight;W>=0;W--){ // only right to left work not left to right works 
                int pick=INT_MIN;
                int notpick=prev[W];
                if(wt[i]<=W)pick=val[i]+prev[W-wt[i]];
                prev[W]=max(notpick,pick);
            }
        }
        return prev[maxWeight];
    }
};
