
// Knapsack with Duplicate Items

class Solution {
  public:
    int solve(int i,vector<int>&val,vector<int>&wt,int W,vector<vector<int>>&dp){
      if(i==0){
         return val[0]*(W/wt[0]);
      }
      if(dp[i][W]!=-1)return dp[i][W];
      int pick=INT_MIN;
      int notpick=solve(i-1,val,wt,W,dp);
      if(wt[i]<=W)pick=val[i]+solve(i,val,wt,W-wt[i],dp);//Each item can be taken any number of times.
      return dp[i][W]=max(notpick,pick);
  }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n=val.size();
        vector<vector<int>>dp(n,vector<int>(capacity+1,-1));
        return solve(n-1,val,wt,capacity,dp);
    }
};

class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n=val.size();
        vector<vector<int>>dp(n,vector<int>(capacity+1,0));
        for(int W=wt[0];W<=capacity;W++){
            dp[0][W]=val[0]*(W/wt[0]);
        }
        for(int i=1;i<n;i++){
            for(int W=0;W<=capacity;W++){
                int pick=INT_MIN;
                int notpick=dp[i-1][W];
                if(wt[i]<=W)pick=val[i]+dp[i][W-wt[i]];//Each item can be taken any number of times.
                dp[i][W]=max(notpick,pick);
            }
        }
        return dp[n-1][capacity];
    }
};


class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n=val.size();
        vector<int>prev(capacity+1,0),temp(capacity+1,0);
        for(int W=wt[0];W<=capacity;W++){
            prev[W]=val[0]*(W/wt[0]);
        }
        for(int i=1;i<n;i++){
            for(int W=0;W<=capacity;W++){
                int pick=INT_MIN;
                int notpick=prev[W];
                if(wt[i]<=W)pick=val[i]+temp[W-wt[i]];//Each item can be taken any number of times.
                temp[W]=max(notpick,pick);
            }
            prev=temp;
        }
        return prev[capacity];
    }
};
