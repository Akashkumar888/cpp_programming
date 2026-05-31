class Solution {
  public:
    int solve(int idx,int prevSum,int n,string &s,vector<vector<int>>&dp){
        if(idx==n)return 1;
        if(dp[idx][prevSum]!=-1)return dp[idx][prevSum];
        int ways=0;
        int currSum=0;
        for(int i=idx;i<n;i++){
            currSum+=(s[i]-'0');
            if(currSum>=prevSum){
                ways+=solve(i+1,currSum,n,s,dp);
            }
        }
        return dp[idx][prevSum]=ways;
    }
    int validGroups(string &s) {
        int n=s.size();
        int maxSum = 9*n;
        vector<vector<int>>dp(n+1,vector<int>(maxSum+1,-1));
        return solve(0,0,n,s,dp);
    }
};


class Solution {
  public:
    int validGroups(string &s) {
        int n=s.size();
        int maxSum=9*n;
        vector<vector<int>>dp(n+1,vector<int>(maxSum+1,0));

        // base case
        for(int prevSum=0;prevSum<=maxSum;prevSum++)dp[n][prevSum]=1;

        for(int idx=n-1;idx>=0;idx--){
            for(int prevSum=maxSum;prevSum>=0;prevSum--){
                int ways=0;
                int currSum=0;
                for(int i=idx;i<n;i++){
                    currSum+=(s[i]-'0');
                    if(currSum>=prevSum){
                        ways+=dp[i+1][currSum];
                    }
                }
                dp[idx][prevSum]=ways;
            }
        }
        return dp[0][0];
    }
};


