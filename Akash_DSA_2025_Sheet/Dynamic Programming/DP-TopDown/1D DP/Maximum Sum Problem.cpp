
class Solution {
  public:
    int solve(int n,vector<int>&dp){
        if(n==0)return 0;
        if(dp[n]!=-1)return dp[n];
        int breakValue = solve(n/2,dp) + solve(n/3,dp) + solve(n/4,dp);

        return dp[n]=max(n,breakValue);
    }

    int maxSum(int n) {
        vector<int>dp(n+1,-1);
        return solve(n,dp);
    }
};

class Solution {
  public:
    int maxSum(int n) {
        vector<int>dp(n+1,0);
        dp[0]=0;
        for(int i=1;i<=n;i++){
        int breakValue = dp[i/2] + dp[i/3] + dp[i/4] ;
        dp[i]=max(i,breakValue);
        }
        return dp[n];
    }
};

class Solution {
  public:
    unordered_map<int,int> dp;
    int solve(int n){
        if(n==0)return 0;

        if(dp.count(n)){
            return dp[n];
        }
        int breakValue=
        solve(n/2)
        +solve(n/3)
        +solve(n/4);

        return dp[n]=max(n,breakValue);
    }
    int maxSum(int n) {
        return solve(n);
    }
};