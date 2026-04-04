class Solution {
public:
    int solve(int n,int same,int k,vector<vector<int>>&dp){
        if(n==1){
            if(same==0) return k;
            else return 0;
        }
        if(dp[n][same]!=-1)return dp[n][same];
        int noOfWays=0;
        if(same==0){
            noOfWays=(solve(n-1,0,k,dp) + solve(n-1,1,k,dp))*(k-1);
        }
        else{
            noOfWays=solve(n-1,0,k,dp);
        }
        return dp[n][same] = noOfWays;
    }
    int countWays(int n, int k) {
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return solve(n,0,k,dp) + solve(n,1,k,dp);
    }
};


class Solution {
public:
    int countWays(int n, int k) {
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        dp[1][0]=k;
        for(int i=2;i<=n;i++){
            for(int same=0;same<2;same++){
                int noOfWays=0;
                if(same==0){
                    noOfWays=( dp[i-1][0] + dp[i-1][1])*(k-1);
                }
                else{
                    noOfWays=dp[i-1][0];
                }
                dp[i][same] = noOfWays;
            }
        }
        return dp[n][0] + dp[n][1];
    }
};


class Solution {
public:
    int countWays(int n, int k) {
        if(n == 1) return k;
        int prev1 = k; // dp[1][0] → different
        int prev2 = 0; // dp[1][1] → same
        
        for(int i=2;i<=n;i++){
                int curr1=( prev1 + prev2)*(k-1);
                int curr2=prev1;
                prev1=curr1;
                prev2=curr2;
        }
        return prev1 + prev2;
    }
};
