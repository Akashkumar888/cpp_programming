
// User function Template for C++

class Solution {
  public:
  int solve(int i,vector<int>&prices,int N,vector<vector<int>>&dp){
      if(i==0){
          return N*(prices[0]);
      }
      if(dp[i][N]!=-1)return dp[i][N];
      int notpick=0+solve(i-1,prices,N,dp);
      int pick=INT_MIN;
      int rodLength=i+1;
      if(rodLength<=N)pick=prices[i]+solve(i,prices,N-rodLength,dp);
      return dp[i][N]=max(pick,notpick);
  }
    int cutRod(vector<int> &prices) {
        // code here
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return solve(n-1,prices,n,dp);
    }
};

// User function Template for C++

class Solution {
  public:
    int cutRod(vector<int> &prices) {
        // code here
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(n+1,0));
        for(int N=0;N<=n;N++)dp[0][N]=N*(prices[0]);
        for(int i=1;i<n;i++){
            for(int N=0;N<=n;N++){
              int notpick=0+dp[i-1][N];
              int pick=INT_MIN;
              int rodLength=i+1;
              if(rodLength<=N)pick=prices[i]+dp[i][N-rodLength];
              dp[i][N]=max(pick,notpick);
            }
        }
        return dp[n-1][n];
    }
};

// User function Template for C++
class Solution {
  public:
    int cutRod(vector<int> &prices) {
        // code here
        int n=prices.size();
        vector<int>prev(n+1,0),temp(n+1,0);
        for(int N=0;N<=n;N++)prev[N]=N*(prices[0]);
        for(int i=1;i<n;i++){
            for(int N=0;N<=n;N++){
              int notpick=0+prev[N];
              int pick=INT_MIN;
              int rodLength=i+1;
              if(rodLength<=N)pick=prices[i]+temp[N-rodLength];
              temp[N]=max(pick,notpick);
            }
            prev=temp;
        }
        return prev[n];
    }
};

